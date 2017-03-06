#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio> 
using namespace std;
const int maxn = 100+5;
char box[maxn][maxn];
int ax,ay,bx,by;
bool ans = 0;
void dfs(int n , int x, int y)
{
	if(x == bx && y == by) ans = 1;
	else for(int i = -1; i <= 1; i++)
	  for(int j = -1; j <= 1 ;j ++)
	  if(i!=j&&x+i>=0&&x+i<n&&y+j>=0&&y+j<n) 
	  {
	  	if(box[i][j]!='#')
	  	dfs(n,x+i,y+j);
	  }
}



int main()
{
	#ifdef LOCAL
	freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	
	int k;
	cin >> k;
	while(k--)
	{
		int n;
		cin >> n;
		for(int i = 0; i < n ; i ++)
		  for(int j = 0; j < n ; j ++) scanf("%c",&box[i][j]);
		cin >> ax >> ay >> bx >> by;
		ans = 0;
		if(box[ax][ay]=='#'||box[bx][by]=='#')
		{
			printf("NO\n");
			continue;
		}else dfs(n,ax,ay);
		if(ans)printf("YES\n");
		else printf("NO\n");
			
	}
	 
	
	
	
	
	return 0;
} 
