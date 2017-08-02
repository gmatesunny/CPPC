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
