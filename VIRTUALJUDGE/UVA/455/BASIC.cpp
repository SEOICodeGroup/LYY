#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio> 
using namespace std;


int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	
	freopen("OUTPUT.txt","w",stdout);
	#endif
	
	int k=0;
	string input ;
	int num;
	cin >> num;
	
	for(int i = 1 ; i<= num ; ++i)
	{
		cin >> input;
		int n = input.length();
		k = 0;
		string c;
		
		for(int j = 1 ;j <= n ; j++)
		{
			bool ans=true;
			for(int m=0;m+j<n;m++)
			{
				if(input[m]!=input[m+j]) {ans = false;break;}
				//if(m+1==j)m+=j;
				if(n%j!=0) ans = false;	
			}
			
			
			
	
		if(ans) {
					cout <<j << endl; break;	
			
			
		}
		
	} 
	
	 
	if(i!=num ) cout << endl;
	
	} 
	
	return 0;}

