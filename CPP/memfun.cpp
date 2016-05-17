#include <iostream>
#include <cstring> //for mem functions
#include <stdlib.h>

using namespace std;
int main(int argc, char ** argv){
    int a[5];
    int *b = (int*) malloc(sizeof(int) * 5);

    memset(a,-1,sizeof(a));

    memcpy(b,a,sizeof(int) * 5); // destination, source, no. of bytes

    a[4] = 9;

    for (unsigned int i = 0; i < 5; i++){ //use unsigned
    	cout <<*(b+i) << "\t";
    }

    if(memcmp(a,b,sizeof(a)) == 0){
    	cout << "\nBoth are equal bitwise" << endl;
    }else{
    	cout << "\nThey are different" << endl;
    }


    return 0;
}
