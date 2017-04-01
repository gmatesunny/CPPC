#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

const int randGen() {
	return rand() % 100;
}

template <typename T>
void display(vector<T> v){
/*		vector<T>::iterator it = v.begin();
		while(it != v.end()){
	Can not make iterator from Template */

	for(unsigned int i = 0; i < v.size(); ++i){
		cout << v[i] << " ";
	}
}

int main(int argc, char **argv){
	vector<int> nums(10);
	srand(time(NULL));
	fill(nums.begin(), nums.end(), 5);
	display(nums);
	generate(nums.begin(), nums.end(), randGen);
	display(nums);
	cout << "\nThe sum of numbers : " << accumulate(nums.begin(), nums.end(), 0) << endl;
	sort(nums.begin(), nums.end());
	display(nums);
	return 0;
}
