#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio> 
using namespace std;
int i , j , k ;

int num[10005];
int book[10005];
int sum = 0;
int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	int n ;
	int x ; 
	cin >> n;
	int max_ =-1;
	for(i = 1; i <= n ; i ++)	{cin >> x ;max_ = max(max_,x) ;num[x] = 1;}	 
	for(i = 1; i <= max_ - 1; i ++)
	{
		for(int j = i + 1; j <= max_  ; j ++)
		{
			if(i + j > max_) break; 
			if(num[i]&&num[j]&&i != j && book[i+j]==0  && 
				num[i+j]==1) {sum ++; book[i+j]=1;		}
		}
	}
	
	cout <<sum<< endl;
	
	
	return 0;
} 
