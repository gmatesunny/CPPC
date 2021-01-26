/* https://practice.geeksforgeeks.org/problems/47e5aa3f32aee9e0405f04960f37c8a562d96a2f/1/?track=30-DOC-day-1&batchId=320 */


#include <bits/stdc++.h>
using namespace std;

class SolutionWithExtraSpace
{
public:
	void prank(long long a[], int n)
	{
		long long temp[n];

		for (int i = 0; i < n; ++i)
		{
			temp[i] = a[i];
		}

		for (int i = 0; i < n; ++i)
		{
			a[i] = temp[temp[i]];
		}
	}
};

class SolutionWithoutExtraSpace
{
public:
	void prank(long long a[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			a[i] = a[i] + (a[a[i]] % n) * n;
		}

		for (int i = 0; i < n; ++i)
		{
			a[i] = a[i] / n;
		}
	}
};

int main()
{
	int n = 6;
	long long a[n] = { 0, 5, 1, 2, 4, 3 };

	SolutionWithoutExtraSpace ob;
	ob.prank(a, n);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}
