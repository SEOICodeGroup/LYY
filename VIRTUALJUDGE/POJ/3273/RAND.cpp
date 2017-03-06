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
	int N = rand()%100000;
	cout <<  N;
	int M = rand()%( N - 1) + 2;
	cout << " "<< M<<endl;
	for(int i= 1; i <= N ; i++){
		cout << rand()%10000<<endl;
	}
} 
