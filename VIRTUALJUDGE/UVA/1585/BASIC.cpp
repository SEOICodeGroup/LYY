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
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	
	
	int num;
	cin >> num;
	
	string input;
	
	for (int i= 1;i<=num ; i++)
	{
		cin >> input;
		int count=0;
		int ans = 0;
		int n = input.length();
		for(int j = 0 ;j < n;j++)
		{
			if(input[j]=='X') {count = 0; ans+= count;	}
			if(input[j]=='O') {count ++ ; ans+= count;	}
		}
		cout << ans;
		cout << endl;
	} 
	
	 
	
	
	
	
	
	
	
	
	
	
	return 0;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
} 
