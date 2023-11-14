/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}}; 
    string roman_representation{"MCMIV"};

    int i = 0;
    int temp = 0;
    int number = 0;;
    while(i<roman_representation.length())
    {
        if(i == roman_representation.length()-1)
        {
            number = number + m[roman_representation[i]];
            ++i;
        }
        else if(m[roman_representation[i+1]] <= m[roman_representation[i]])
        {
            number = number + m[roman_representation[i]];
            ++i;
        }
        else
        {
            number = number + (m[roman_representation[i+1]] - m[roman_representation[i]]);
            i = i+2;
        }
    }
    cout << number << endl;
    return 0;
}
