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
} 
