#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3fffffff
int n, a[5017];
int dfs(int sl, int sr)
{
	int MIN = INF, num = 0;
	if(sl > sr)
	return 0;
	for(int i = sl; i <= sr; i++)
	{
		if(a[i] < MIN)
		{
			MIN = a[i];
		}
	}
	for(int i = sl; i <= sr; i++)
	{
		a[i]-=MIN;
	}
	num+=MIN;
	int ll = sl;
	for(int i = sl; i <= sr; i++)
	{
		if(a[i] == 0)//如果a[i]=0,中断处 
		{
			num+=dfs(ll,i-1);
			ll =i+1;
		}
	}
		if(ll <= sr)//最后一根不是零的情况 
		{
			num+=dfs(ll,sr);
		}
	return min(num,sr-sl+1);
}
int main()
{
	int i, j;
	while(cin>>n)
	{
		for(i = 1; i <= n; i++)
		{
			cin>>a[i];
		}
		int ans = dfs(1,n);
		cout<<ans<<endl;
	}
	return 0;
}
