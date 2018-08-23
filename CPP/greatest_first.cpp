 /*
Given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
Given A = [1, 2, 3], the function should return 4.
Given A = [−1, −3], the function should return 1.
*/

#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    auto i = 1, j = 0;
    sort(begin(A), end(A));
    while(j < (int)A.size())
    {
        if(A[j]+1 < A[j+1])
            break;
        j++;
        i++;
    }
  
    return i;
}
