#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
    deque<int> hist;
    
    
    int i=0;
    char str[]="Mamma";
    while (str[i])
    {
    if (isalpha(str[i])) 
    {
        
        if(find(begin(hist), end(hist), str[i])== hist.end())
        {

            if(hist.size() == 3)
            {
                hist.pop_back();
            }
            
            hist.push_back(str[i]);
            cout << str[i];
            cout << ":Not found in history\n";
            
        }
        else
        {

         if(hist.size() == 3)
            {
                hist.pop_back();
            }
            hist.push_back(str[i]);
        }
    }
    i++;
      }
    
    return 0 ;
}
