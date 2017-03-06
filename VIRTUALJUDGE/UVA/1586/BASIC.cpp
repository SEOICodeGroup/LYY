#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio> 
#include <math.h>
using namespace std;


int main()
{
	#ifdef LOCAL
	freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	
	int num ;
	cin >> num;
	
	for(int i = 1;i <= num ; i ++) 
	{
		double ans = 0;
		string input ; 
		cin >> input ;
		int n = input.length();
		int k = 1;
		bool single = true ;
		for (int j = n-1; j >= 0 ; j--)
		{
			if(input[j]=='C') {ans += 12.01 * k; k = 1;single=true;}
			else if(input[j]=='H') {ans += 1.008 * k; k = 1;single=true;}
			else if(input[j]=='O') {ans += 16.00 * k ; k = 1;single=true;}
			else if(input[j]=='N') {ans += 14.01 * k; k = 1;single=true;}
			else if (input[j]-'0'<10&&single){k = input[j]-'0'; single = false  ;}
			
			else k = k + (input [j]-'0') * 10;
			
		}
		cout << setprecision(3)<< setiosflags(ios::fixed) << ans << endl;
		
	}
	
	 
	
	
	
	
	return 0;
} 
