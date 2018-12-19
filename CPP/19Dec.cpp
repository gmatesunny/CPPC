#include <iostream>
using namespace std;

int main() {

	int32_t tc{0};
  	cin >> tc;
	while(tc--)
	{
	int32_t n{0}, d{0}, n1{0}, n2{0}, nValue{0}, j{2};
    	cin >> n1 >> n2;
    	cin >> n;
    	d = n2-n1;
        nValue = n1 + (n - 1)*d;
    /*	if(n == 1)
    	{
    	    nValue = n1;
    	}
    	else
    	{
    	    nValue = n2;
    	    while(j<n)
        	{
        	    j++;
        	    nValue = nValue + d;
        	}
    	} */
    	cout << nValue << endl;
	}
	return 0;
}
