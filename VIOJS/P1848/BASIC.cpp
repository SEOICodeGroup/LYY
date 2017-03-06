#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio> 
using namespace std;
int dp[10000001];

int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	int num;
	int k ;
	cin >> num >> k;
	dp[k] = 1;
	long long sum = k==0?0:1 ;
	for(int i = 10; i <= num ; i++)
	{
		dp[i] = dp[i%10];
		dp[i] += dp[i/10]; 
		sum += dp[i];
	} 
	
	cout << sum;
	
	
	
	return 0;
} 
