 /*
Given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.
Given A = [−1, −3], the function should return 1.
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

 int solution(vector<int> &A) {
    auto i = 0, j = 0;
    sort(begin(A), end(A));
    
    if(A[(int)A.size()-1] < 1)
        return 1;    
            
    while(A[j]< 1)
        j++;
  
    if(A[j] > 1)
        return 1;

  while(j < (int)A.size())
    {         
        if(j+1 < (int)A.size() && A[j+1] - A[j] > 1)
            return A[j] + 1;
        j++;
    }
  
    return A[j-1] + 1;  
}
