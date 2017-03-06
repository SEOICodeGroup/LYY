#include<iostream>
#include <cstdio>
#include <cstring>
struct Edge{int u,v,next,mark;};
int Set[100005],N,M,cnt,ans;
Edge First[10005];  //mark v -
Edge R[100005];


using namespace std;

bool bfs(int k)
{
	int i = First[k].next;
	while(i)
	{
		if(First[R[i].u].mark == First[k].mark) i = R[i].next;
		
		
	}
	
	return true;
}


void Ins( int a, int b )
{
	R[cnt++].u = a; R[cnt].v = b; R[cnt].next = First[a].next; First[a].next = cnt;
	R[cnt++].u = b; R[cnt].v = a; R[cnt].next = First[b].next; First[b].next = cnt;
}
int main()
{
	scanf("%d%d",&N,&M);
	memset(R,0,sizeof(R));
	for(int i = 1; i <= M ; i++ )
	{
		int a, b;
		scanf("%d%d",&a,&b);
		Ins(a,b);
	}
	
	
	for(int i = 1; i <= N ; i++)
	{
		if(First[i].mark == 0) 
		{
			bool flag = dfs(i);
			if(!flag) cout << "Im";
		}
	}
	if(!bfs(1))cout <<"I";
	return 0;
} 
