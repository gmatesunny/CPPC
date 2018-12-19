// russianPeasant.cpp : Defines the entry point for the console application.
//

#include <bits/move.h>
#include <cstdio>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

void zeroAtEnd_one(vector<int> &a) {
	unsigned int k = 0;
	for (unsigned int i = 0; i < std::size(a); ++i) {
		if (a.at(i) != 0) {
			a.at(k) = a[i];
			k++;
		}
	}
	while (k < size(a)) {
		a.at(k) = 0;
		k++;
	}

}

void zeroAtEnd_two(vector<int> &b) {
	unsigned int k = 0, l = size(b) - 1;
	while (k < l) {
		if (b[k] == 0) {
			if (b[l] != 0) {
				swap(b[k], b[l]);
			}
			--l;
		} else {
			++k;
		}
	}

}

int main() {
	vector<int> a = { 30, 10, 20, 15, 25, 0, 0, 54, 23, 0, 11, 2 };
	vector<int> b { a };

	for (auto i : a) {
		cout << i << " ";
	}
	cout << endl;
	zeroAtEnd_one(a);
	for (auto i : a) {
		cout << i << " ";
	}

	cout << endl;

	for (auto i : b) {
		cout << i << " ";
	}
	cout << endl;
	zeroAtEnd_one(b);
	for (auto i : b) {
		cout << i << " ";
	}

	getchar();
	return 0;
}

