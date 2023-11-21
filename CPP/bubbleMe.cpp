#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void bubble(vector<int>& v)
{
    
    for(int i = 0; i<v.size()-1; ++i)
    {
        for(int j = 0; j<v.size() - 1 -i; ++j)
        {
            if (v.at(j) > v.at(j+1))
                swap(v.at(j), v.at(j+1));
        }
    }

    for(auto &i: v)
    {
        cout << i << " " << endl;
    }
}

int main()
{
    std::vector<int> v{8,9,3,4,5,6,7};
    bubble(v);
    return 0;
}
