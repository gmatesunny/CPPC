//some notes while studying c++ 

    myMap.insert(pair<char,int>{'d',4});    
    for(auto i=begin(myMap);i!=end(myMap);++i){
        cout<<i.first<<":"<<i.second<<endl;---> fails as begin returns the pointer object to the element
        cout<<i->first;--> correct
    }
    
    for(auto i: myMap)
    {
        cout<<i.first<<":"<<i.second<<endl; ------> this returns referece object so no pointer dereference
    }

Internally, the elements in the unordered_map are not sorted in any particular order with respect to either their key or mapped values, but organized into buckets depending on their hash values to allow for fast access to individual elements directly by their key values (with a constant average time complexity on average).
