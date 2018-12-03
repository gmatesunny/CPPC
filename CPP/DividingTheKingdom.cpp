/*
An old king wants to divide his kingdom between his two sons. He is well known for his justness and wisdom, and he plans to make a good use of both of these attributes while dividing his kingdom.

The kingdom is administratively split into square boroughs that form an N × M grid. Some of the boroughs contain gold mines. The king knows that his sons do not care as much about the land as they do about gold, so he wants both parts of the kingdom to contain exactly the same number of mines. Moreover, he wants to split the kingdom with either a horizontal or a vertical line that goes along the borders of the boroughs (splitting no borough into two parts).

The goal is to count how many ways he can split the kingdom.

Write a function:

int solution(int N, int M, vector<int> &X, vector<int> &Y);

that, given two arrays of K integers X and Y, denoting coordinates of boroughs containing the gold mines, will compute the number of fair divisions of the kingdom.

For example, given N = 5, M = 5, X = [0, 4, 2, 0] and Y = [0, 0, 1, 4], the function should return 3. The king can divide his land in three different ways shown on the picture below.

Divide horizontally in two ways or vertically in one way
Write an efficient algorithm for the following assumptions:

N and M are integers within the range [1..100,000];
K is an integer within the range [1..100,000];
each element of array X is an integer within the range [0..N−1];
each element of array Y is an integer within the range [0..M−1].
*/


#include <map>

using namespace std;

int solution(int n, int m, vector<int> &x, vector<int> &y)
{
    map<int,int> row_map;
    map<int,int> col_map;
    int h_div{0}, v_div{0};
    
    if(x.size() != y.size())
        return 0;
        
    for(auto i = 0; i<x.size();i++)
    {
        row_map[x[i]] =  row_map[x[i]]+1;
        col_map[y[i]] =  col_map[y[i]]+1;        
    }
    
    
    int row_sum_till_now{0}, col_sum_till_now{0};
    
    for(auto i = 0; i<=n;i++)
    {
        row_sum_till_now += row_map[i];
        if(row_sum_till_now ==  (x.size() - row_sum_till_now))
            h_div++;
    } 
    
    for(auto i = 0; i<=m;i++)
    {
        col_sum_till_now += col_map[i];            
        if(col_sum_till_now ==  (x.size() - col_sum_till_now))
            v_div++;
    }
    
    return h_div + v_div;   
}
    
int main() 
{  
    vector<int> x{0,4,2,0};
    vector<int> y{0,0,1,4};
    
    cout << solution(5,5,x,y);
    return 0;
}   
