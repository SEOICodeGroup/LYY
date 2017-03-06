#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <cstdio> 
using namespace std;

int n[505];
int x[3100000];
int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	
	int num ;
	cin >> num ; 
	//ÂóÉ­ 2<<num - 1;
	n[0] = 2;
//	while(1);
//	{
	for(int i = 0 ;i <= 500 ;i ++)
	{
		for(int j = 1; j <= num -1 ;j++)
		{
			n[i]<<=1;
			if(i!=0) n[i]+=x[j];
			
			x[j] = n[i]/10;
			n[i]%=10;
		}
		
		/*int k = strlen(n) + 1;
		int x= 0;
		for(int j = 0; j <= k ; j++)
		{
			//n[j] <<= 1;
			n[j] *=2;
			n[j] += x;
			x = n[j]/10;
			n[j]%=10;
		}
		*/
	} 
	printf("%d",n[499]);
	for(int i = 498 ; i>=1 ; i--)
	{
		
		if((i+1) % 50  == 0 && i != 0) printf("\n");
		printf("%d",n[i]);
	}
	printf("%d",n[0]-1);
//	}
	return 0;
} 
