#include<bits/stdc++.h>
using namespace std;

stringstream ss;
int main(int argc, char *argv[]) {
	int seed = time(NULL);
	if(argc) {
		ss.clear();
		ss << argv[1];
		ss >> seed;
	}
	srand(seed);
	int n = rand() % 5000;
	cout << n << endl;
	for(int i = 1; i <= n ; i ++){
		cout << rand()<<" ";
	} 
} 
