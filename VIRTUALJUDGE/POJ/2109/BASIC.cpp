#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
#include <cstdio> 
using namespace std;
int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	double n, p;
	while(cin >> n >> p){
		int l = 0 ,r  = pow(10,9);
		while(1){
			int m = (l+r)/2;
			double c = pow(m,n);
			if(p == c) {
				cout << m << endl;break;
			}else{
				if(p > c) l = m + 1 ;
				else r = m;
			}
		}
	}	
	return 0;
} 
