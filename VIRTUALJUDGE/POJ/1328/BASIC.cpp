#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
int n,d,Case;
struct P{int x,y;double dist;}p[1005];
bool cmp (const P b, const P a){return b.x < a.x;} 
bool check(int i){
	
	int a = d *d, b = p[i].y*p[i].y;
	if(a<b||d<=0)return false;
	p[i].dist = double(sqrt(a-b));
	cout << p[i].dist;
	return true;
}

void input()
{
	for(int i = 1; i <= n ; i++){
		scanf("%d%d",&p[i].x,&p[i].y);
	}
	
}

void solve(){
	while(scanf("%d%d",&n,&d))
	{
	    if(n==0&&d==0)return;
		input();int ans = 0;
		for(int i = 1; i <= n; i++){
			if(!check(i)){ans = -1;}
		}
		sort(p+1,p+n+1,cmp);
		int i = 1;
		while(i<=n&&ans!=-1)
		{
			double k = p[i].x+ p[i].dist;
			ans++;i++;
			while(k  >= p[i].x*1.0 - p[i].dist)i++;
		}
		cout <<"Case "<<++Case<<": "<< ans<<endl;
	}
	//4 5 -5 3 -3 4 2 3 3 3
}
int main()
{
	solve();
	

	return 0;
}
