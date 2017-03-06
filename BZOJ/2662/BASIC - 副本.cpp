#include <iostream>
#include <string>
#include <cstdio>
#include <ext/pb_ds/priority_queue.hpp>
#define pr pair<int , pair <int , int> > 
#define mp(a,b,c) make_pair(a,make_pair(b,c))
using namespace std;
using namespace __gnu_pbds;
typedef __gnu_pbds::priority_queue<pr,greater<pr>,pairing_heap_tag > heap;
heap::point_iterator id[55][55];
struct Edge
	{int to,v,next;};
Edge E[2005];
int ans = 0,last[55];
int M,N,K,cnt;
int dis[55][55];
const int INF = 1000000000;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Ins(int u, int v , int w)
{
	E[++cnt].to = v; E[cnt].next = last[u]; last[u] = cnt; E[cnt].v = w;
	E[++cnt].to = u; E[cnt].next = last[v]; last[v] = cnt; E[cnt].v = w;
}
void Dijkstra(int v)
{
    for(int i = 1; i <= N ; i++ )
    	for(int j = 0; j <= K ; j++ )
    {
        dis[i][j] = INF;
    }
	heap q;
	dis[1][0] = 0; id[1][0] = q.push(mp(0,1,0));
    //S[v] = 1;
    //q.push(Edge(v,dist[v],0));
    while(!q.empty())
    {
    	int a = q.top().second.first; int b = q.top().second.second; q.pop();
    	for(int i = last[a] ; i ; i = E[i].next)
    	{
    		
    			if(dis[a][b]+E[i].v<dis[E[i].to][b])
			{
				dis[E[i].to][b]=dis[a][b]+E[i].v;
				if(id[E[i].to][b]==0)id[E[i].to][b]=q.push(mp(dis[E[i].to][b],E[i].to,b));
				else q.modify(id[E[i].to][b],mp(dis[E[i].to][b],E[i].to,b));
			}
			if(b<K&&dis[a][b]+E[i].v/2<dis[E[i].to][b+1])
			{
				dis[E[i].to][b+1]=dis[a][b]+E[i].v/2;
				if(id[E[i].to][b+1]==0)id[E[i].to][b+1]=q.push(mp(dis[E[i].to][b+1],E[i].to,b+1));
				else q.modify(id[E[i].to][b+1],mp(dis[E[i].to][b+1],E[i].to,b+1));
			}
    			
    		
    	}
	}
}
int main()
{
    #ifdef LOCAL
    //freopen("TEXT.txt","r",stdin);
    //freopen("OUTPUT.txt","w",stdout);
    #endif
   N = read(); M = read();K = read();




    for(int i = 1; i <= M ; i++ )
    {
        int u = read(), v = read() , k = read();
        //E[Ai][Bi] = E[Bi][Ai] = Timei ;
        Ins(u,v,k);
    }
    Dijkstra(1);
    ans = INF;
    for(int i = 0 ; i <=K ; i++)
    {
    	ans = min(ans, dis[N][i]);
	}
	printf("%d",ans);
    return 0;
}
