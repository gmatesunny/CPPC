#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <map>
#include <set>
using namespace std;

//http://thispointer.com/how-to-sort-a-map-by-value-in-c/  


int main()
{
    map<char,int> myMap{
        {'a',11},
        {'b',22},
        {'c',13},
        {'d',13},
    };
    
    myMap.insert(pair<char,int>{'x',-22});
    
    for(auto &i: myMap)
    {
        cout<<i.first<<":"<<i.second<<endl;
    };
    
    cout<<"============================="<<endl;

    typedef function<bool(pair<char, int>, pair<char, int>)> comparator;//todo: learn function more
    
    comparator compFunctor = [](pair<char,int> elem1, pair<char, int> elem2)
    {
        return elem1.second <= elem2.second;
    };
    
    set<pair<char,int>, comparator> mySet(begin(myMap), end(myMap), compFunctor);
    
    for(auto &i: mySet)
    {
        cout<<i.first<<":"<<i.second<<endl;
    }    
    
    
    
    return 0;

    
    
}
