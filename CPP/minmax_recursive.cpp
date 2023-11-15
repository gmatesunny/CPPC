#include <iostream>
#include <utility>
#include <vector>

using namespace std;
pair<int, int> get_minmax(vector<int> data, int l, int r)
{
    pair<int, int> minmax;
    
    if(l == r)
    {
        minmax.first = data[l];
        minmax.second = data[l];
    }
    
    else if(r == l+1)
    {
        if(data[l] <= data[r])
        {
            minmax.first = data[l];
            minmax.second = data[r];            
        }
        else
        {
            minmax.first = data[r];
            minmax.second = data[l];               
        }
    }
    
    else
    {
        pair<int, int> minmax_left;
        pair<int, int> minmax_right;
        
        int mid = l + (r-l)/2;
        minmax_left= get_minmax(data,  l, mid);
        minmax_right = get_minmax(data,  mid+1, r);
        
        if(minmax_left.first <= minmax_right.first)
        {
            minmax.first = minmax_left.first;
        }
        else
        {
            minmax.first = minmax_right.first;
        }
        
        if(minmax_left.second >= minmax_right.second)
        {
            minmax.second = minmax_left.second;
        }
        else
        {
            minmax.second = minmax_right.second;
        }
    }
    
    return minmax;    
}

int main()
{
    pair<int, int> minmax;
    vector<int> v {4, 2, 0, 8, 20, 9, 2};
    minmax = get_minmax(v, 0, v.size()-1);
    
    cout << "Min: " << minmax.first << " Max: " << minmax.second << endl;

    return 0;
}
