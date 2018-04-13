#include "../drafts/zmq/include/headers.hpp"

#include <thread>
#include <boost/algorithm/string.hpp>
#include <boost/program_options.hpp>
#include <future>

#include <numeric>
#include "include/series.hpp"

using namespace std;
using namespace boost::program_options;


#define col 0


void compare(vector<double> &v1, vector<double> &v2) {
    if (v1.size() != v2.size()) {
        BOOST_LOG_TRIVIAL(fatal) << "series are not of the same size";
        exit(-3);
    }
}


// Parallel sum
template<typename InputIt>
pair<long, double> parallelAccumulate(InputIt start, InputIt last, double init) {
    auto size = distance(start, last);
    int parts = 0;
    if(size >= 100)
        parts = thread::hardware_concurrency();
    else
        parts = 2;
    vector<future<double>> futures;

    for (size_t i = 0; i != parts; ++i) {
        const auto part_size = (size * i + size) / parts - (size * i) / parts; //remember this formula

        futures.emplace_back(async(launch::async, [=] {
            return accumulate(start, next(start, part_size), init);
        }));
        advance(start, part_size);
    }

    double sum = 0.0;
    BOOST_LOG_TRIVIAL(trace) << "Getting back the value from futures";
    for (auto &a: futures)
        sum = sum + a.get();
    //TODO: should have used the accumulate again but can't get future.get() correct in lambda
    pair<long, double> pairSizeSum = {make_pair(size, sum)};
    return pairSizeSum;
}


double correlationB(vector<double> &vx, vector<double> &vy)
{
    compare(vx, vy);
    double sumx = 0, sumy = 0, sumxy = 0;
    double sumsqrx = 0, sumsqry = 0;

    for (unsigned int i = 0; i < vx.size() ; i++){
        sumxy = sumxy + vx[i] * vy[i];
        sumx = sumx + vx[i];
        sumy = sumy + vy[i];
        sumsqrx = sumsqrx + pow(vx[i],2);
        sumsqry = sumsqry + pow(vy[i],2);
    }
    return (vx.size()*sumxy - (sumx*sumy)) \
           /((sqrt(vx.size()*sumsqrx - pow(sumx,2)))*(sqrt(vy.size()*sumsqry - pow(sumy,2))));

}

int main(int argc, const char *argv[]) {

    boost::log::trivial::severity_level log;
    options_description desc{"Options"};
    desc.add_options()
            ("help,h", "computes cross correlation")
            ("log,l", value<boost::log::trivial::severity_level>(&log), "define logging level")
            ("files,f",value<vector<string>>()->multitoken()->required(),"input time-series csv files");

    variables_map vm;
    store(parse_command_line(argc, argv, desc),vm);

    if (vm.count("help")) {
        cout << desc << '\n';
        exit(-1);
    }
    notify(vm);

    auto csv = vm["files"].as<vector<string>>();
    if (vm.count("log"))
        setLogFilter(log);

//    setLogFilter();

    BOOST_LOG_TRIVIAL(trace) << "Part 0: loading time-series";
    vector<shared_ptr<series>> ts;
//    ts.reserve(csv.size()); TODO: to avoid reallocation and creating dangling pointer, Do I need it ?
    vector<future<int>> futures;
    for (unsigned int i = 0; i != csv.size(); ++i) {
        shared_ptr<series> ptr{new series(csv[i])};
        ts.push_back(move(ptr));
        futures.emplace_back(async(launch::async, &series::loadData, ts[i], col));
    }

    for (auto &a: futures) {
        a.get();
    }


    auto start = chrono::steady_clock::now();
    vector<vector<double> > result(csv.size(), vector<double>(csv.size(), 0));
    for (unsigned int i = 0; i < ts.size(); i++) {
        for (unsigned int j = 0; j < ts.size(); ++j) {
            if (i == j) {
                result[i][j] = 1;
                continue;
            } else if (i < j)
                result[i][j] = correlationB(ts[i]->data, ts[j]->data);
            else
                result[i][j] = result[j][i];
        }

    }
    BOOST_LOG_TRIVIAL(info) << "Pearson Cross-Correlation Matrix : Version B\nComputation Time:"
                            << chrono::duration<double, milli>(chrono::steady_clock::now() - start).count() << " ms\n";

    for (unsigned int i = 0; i < result.size(); i++) {
        for (unsigned int j = 0; j < result.size(); j++) {
            cout << result[i][j] << "\t";
        }
        cout << "\n";
    }


    BOOST_LOG_TRIVIAL(trace) << "Part 1: finding mean";
    start = chrono::steady_clock::now();
    vector<pair<long, double>> tsSizeSum;
    for (unsigned int i = 0; i != csv.size(); ++i) {
        tsSizeSum.push_back(parallelAccumulate(begin(ts[i]->data), end(ts[i]->data), 0.0));
    }

    vector<double> tsMean;
    for (unsigned int i = 0; i != csv.size(); ++i) {
        tsMean.emplace_back(tsSizeSum[i].second / tsSizeSum[i].first);
    }

    BOOST_LOG_TRIVIAL(trace) << "Part 2: finding correlation pairs";
    vector<double> tsPairs(csv.size() * (csv.size() - 1) / 2, 0);
    vector<pair<int, int>> combi;
    giveCombinations(combi, csv.size());//01--02--03--12--13--23

    //Assuming all series have same size
    map<pair<int, int>, double> abovePairs;
    map<int, double> below;
    BOOST_LOG_TRIVIAL(trace) << "Part 3: finding correlation";
    for (unsigned int i = 0; i < tsSizeSum[0].first; ++i) {
        int j = 0;
        while (j < tsPairs.size()) {
            abovePairs[combi[j]] = abovePairs[combi[j]] +
                                   (ts[combi[j].first]->data[i] - tsMean[combi[j].first]) *
                                   (ts[combi[j].second]->data[i] - tsMean[combi[j].second]);
            below[combi[j].first] =
                    below[combi[j].first] +
                    pow(ts[combi[j].first]->data[i] - tsMean[combi[j].first], 2) / (csv.size() - 1);
            below[combi[j].second] = below[combi[j].second] +
                                     pow(ts[combi[j].second]->data[i] - tsMean[combi[j].second], 2) / (csv.size() - 1);
            ++j;
        }
    }
    BOOST_LOG_TRIVIAL(info) << "Pearson Cross-Correlation Matrix : Version C\nComputation Time:"
                            << chrono::duration<double, milli>(chrono::steady_clock::now() - start).count() << " ms\n";

    vector<double> results;
    unsigned int j = 0;
    while (j < tsPairs.size()) {
        results.emplace_back(abovePairs[combi[j]] / sqrt(below[combi[j].first] * below[combi[j].second]));
        ++j;
    }

    for (auto &a: results)
        cout << a << "\t";

    BOOST_LOG_TRIVIAL(info) << "\n=============DONE=============";
    return 0;
}

