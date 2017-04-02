#include <iostream>
#include <cstring>

using namespace std;

void permute(string _nstr, int postoswap, const int len) {

    //base case when postoswap reaches the last character
    if (postoswap == len - 1) {
        cout << _nstr << endl;
        return; //back to previous stack frame
    }
    //for swapping postoswap to different characters in a string
    for (int j = postoswap; j < len; j++) {
        if (postoswap != j && (_nstr[postoswap] == _nstr[j])) {

        } else {
            swap(_nstr[postoswap], _nstr[j]);
            permute(_nstr, postoswap + 1, len);
            // Beacause swapped one character, so move to next with postoswap+1, remember this is just in fun call
            swap(_nstr[postoswap], _nstr[j]); //backtrack to original
        }
    }

}

int main() {
    int n = 789;
    auto nstr = to_string(n).c_str(); //only to_string gives conversion error of basic_string<char>’ to ‘const char*’
//    cout<<typeid(nstr).name()<<endl;

    permute(nstr, 0, strlen(nstr));
    return 0;
}