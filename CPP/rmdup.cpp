#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

    int a[] = {4, 6, 6, 2, 4, 7, 8, 6, 5, 7};
    int length = sizeof(a)/ sizeof(a[0]);

    for(int i = 0; i < length; i++)
        cout << a[i] << " ";
/*
 * In outer loop traverse aa right till 2nd last element, keeping current 1 right than aa 
 * in inner loop traverse current right till end and change the duplicate with the last element and move left end by one
 */

    cout << "After removing duplicates" << endl;
    int *end = a + length - 1;
    int *aa = a; 
    int *current;
    for(current = aa+1;aa < end;aa++, current = aa+1){
        while(current<=end){
            if(*current == *aa){
                *current = *end;
                end--;
            }
            else{
                current++;
            }
        }
    }
    for(int *i = a; i <= end; i++)
        cout << *i << " ";

    vector<int> s{2, 3, 2, 5, 6, 2, 3, 6, 5, 9};
    for (auto i = s.begin(), j = s.end() - 1; i < j; ++i) {
        for (auto k = i + 1; k <= j; ++k) {
            if (*k == *i) {
                *k = *j;
                s.pop_back();
                j--;
            }
        }
    }

    return 0;
    }
