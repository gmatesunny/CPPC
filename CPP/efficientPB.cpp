
#include <iostream>
#include <vector>
#include <ctime>
#include <random>
#include<string>

using namespace std;

int main()
{
	vector<string> family = { "Anil", "Ladly", "Amit", "Leena", "Roshan" };
	srand(time(NULL));
	vector<int> pb = { 30, 10, 20, 15, 25 };
	vector<int> csum = { 30, 40, 60, 75, 100 };
	
	


	int i = 10;
	while (i > 0) {
	int r = rand() % 100 + 1;
	int low = 0;
	int high = csum.size() - 1;
	cout << "Random Number: " << r << endl;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (r > (csum[mid]))
			{
				low = mid + 1;
			}
			else if (r < (csum[mid] - pb[mid]))
			{
				high = mid - 1;
			}
			else
			{
				cout << family[mid] << endl;
				break;
			}
		}
		--i;
	}



	getchar();
	return 0;
}

