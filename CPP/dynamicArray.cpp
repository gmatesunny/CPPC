#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct User{
	string name;
	int noDays;
};

User *growArray(User *friends, int *size){
	User *new_friends = new User[*size * 2];
	for(int i=0;i<*size;i++){
		new_friends[i].name = friends[i].name;
		new_friends[i].noDays = friends[i].noDays;
	}
	*size *=2;
	delete[] friends;
	return new_friends;
}


int main(int argc, char **argv)
{
	int size = 2;
	int next_element = 0;
	User *friends = new User[size];
	while(1)
	{
		cout << "Please enter your friend's name or q to exit"<<endl;
		cin >> friends[next_element].name;
		if (friends[next_element].name == "q"){
			break;
		}
		cout << "Please enter no of days you last spoke to them:"<<endl;
		cin >> friends[next_element].noDays;
		if (size == ++next_element){
			friends = growArray(friends, &size);
		}
	}
	cout << "Do you want to print the list ? (y/n)"<<endl;
	string choice;
	cin >> choice;
	if(choice == "y"){
		cout << "List:\n";
		for(int i = 0; i < next_element; i++){
			cout << friends[i].name << '\t'<< friends[i].noDays << "\n";
		}
	}
	return EXIT_SUCCESS;


}


