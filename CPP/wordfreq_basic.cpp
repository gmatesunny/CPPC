#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
   int numstring, count=0;
   cin>>numstring;
   string name;
   vector<string> entrywords;
   for(auto i=0;i<numstring;++i){
       cin>>name;
       entrywords.push_back(name);
   }

   cin>>numstring;
   vector<string> querrywords;
   for(auto i=0;i<numstring;++i){
       cin>>name;
       querrywords.push_back(name);
   }

   for(auto j:querrywords){
       for(auto k:entrywords){
           if(j==k){
               count++;
           }
       }
       cout<<count<<endl;
       count=0;
   }

   return 1;

}
