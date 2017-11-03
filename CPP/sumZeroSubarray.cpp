#include <iostream>
#include <unordered_map> 
#include<string>


using namespace std;

void printallSubarrays(int arr[], int n)
{
	unordered_multimap<int, int> map; //<sumSeenTillNow, arrIndex>, non-unique key valie i.e. sum
	map.insert(make_pair(0, -1)); //for one which starts at index 0

	int sum = 0;
	//idea: if sum is seen before there from index at sum starts to current i summation equals 0
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];

		if (map.find(sum) != map.end())
		{
			auto it = map.find(sum);
			while (it != map.end() && it->first == sum)
			{
				cout << it->second + 1 << ".." << i << endl;
				++it;
			}
		}

		map.insert(make_pair(sum, i));
	}
}


int main()
{
	int arr[] = { 3,4,-7,3,1,3,1,-4,-2,-2 };
	int n = size(arr);
	printallSubarrays(arr, n);
	getchar();
	return 0;
}

