// mulWOmul.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int a = 1, b = 8;

	int res = 0;
	while (b >= 1) {
		if (b & 1) // b%2 != 0
		{
			res = res + a;
		}

		a = a << 1;
		b = b >> 1;
	}

	cout << res << endl;
	getchar();


	return 0;
}

