#pragma once

#ifndef CORRELATION_SERIES_HPP
#define CORRELATION_SERIES_HPP

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/log/trivial.hpp>

using namespace std;

class series {
private:
    string filename;
public:
    vector<double> data;

    series(string _filename);

    int loadData(const int col);

    void readdata() const;

};

series::series(string _filename) : filename(_filename) {}

void series::readdata() const {
    for (auto &i: data)
        cout << i << " ";
}

//for loading the data
int series::loadData(const int col = 0) {
    ifstream input(filename);

    if (!input) {
        BOOST_LOG_TRIVIAL(fatal) << "time-series csv file failed to open";
        exit(-2);
    }
    string line;
    //https://stackoverflow.com/questions/5605125/why-is-iostreameof-inside-a-loop-condition-considered-wrong
    while (getline(input, line)) {
        if (!line.empty()) {
            vector<string> oneLine;
            boost::split(oneLine, line, boost::is_any_of("|"));
            boost::trim(oneLine[col]);
            data.push_back(boost::lexical_cast<double>(oneLine[col]));
        }
    }

    return 1;
}

#endif //CORRELATION_SERIES_HPP
