#include<bits/stdc++.h>
using namespace std;
long long a[1005];
stringstream ss;
int main(int argc, char *argv[]) {
	int seed = time(NULL);
	if(argc) {
		ss.clear();
		ss << argv[1];
		ss >> seed;
	}
	srand(seed);
	int n = rand()%1000;
	int k = rand()%n;
	cout << n <<" "<<k<<endl;
	for(int i = 1;i <= n ; i++) a[i] = (rand()*1000)%1000000000;
	for(int i = 1;i <= n ; i++) printf("%d ",rand()%a[i]);
	cout << endl;
	for(int i = 1; i <= n; i++)cout << a[i]<<" ";
	cout<<endl;
	n = rand()%1000;
    k = rand()%n;
	cout << n <<" "<<k<<endl;
	for(int i = 1;i <= n ; i++) a[i] = (rand()*1000)%1000000000;
	for(int i = 1;i <= n ; i++) printf("%d ",rand()%a[i]);
	cout << endl;
	for(int i = 1; i <= n; i++)cout << a[i]<<" "; 
	cout<<"0 0"; 
} 
