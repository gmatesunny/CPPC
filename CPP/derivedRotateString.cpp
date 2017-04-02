#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool extraSpaceCheck(string in, string out) {
    if ((in + in).find(out) != -1) {
        return true;
    }
    return false;
}

bool checkRotate(string in, string out) {
    for (unsigned int i = 0; i < in.length(); ++i) {
        rotate(begin(in), begin(in) + 1, end(in));
        if (out == in) {
            return true;
        }
    }
    return false;
}

int main() {
    string in = "sunny";
    string out = "nnysu";


    if ((in.length() == out.length()) && extraSpaceCheck(in, out)) {
        cout << "extraSpaceCheck: Yes, they are rotating substring." << endl;
    } else {
        cout << "extraSpaceCheck: No, they are not rotating substring." << endl;
    }

    if ((in.length() == out.length()) && checkRotate(in, out)) {
        cout << "checkRotate: Yes, they are rotating substring." << endl;
    } else {
        cout << "checkRotate: No, they are not rotating substring." << endl;
    }
    return 0;
}