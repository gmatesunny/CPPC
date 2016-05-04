#include <iostream>
#include <set>
using namespace std;

void primeGen(int n){
	set<int> primes;
	for(int i = 2;i <=n; ++i){
		primes.insert(i);
	}
	set<int>::iterator it;
	for(int multiplier = 2; multiplier*multiplier <=n; ++multiplier){
		it = primes.find(multiplier);
		if (it != primes.end()){
			for(int k = 2*multiplier; k<=n ; k += multiplier){
				it = primes.find(k);
				if (it != primes.end()){
					primes.erase(*it);
				}
			}
		}
	}
		for(set<int>::iterator iter = primes.begin(); iter != primes.end();
				 ++iter){

			cout << *iter << " ";

		}
	}


int main(int argc, char **argv){
	int n;
	cout << " Enter upper limit" << endl;
	cin >> n;
	primeGen(n);
	return 0;
}