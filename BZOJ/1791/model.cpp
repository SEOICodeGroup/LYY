#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for (int i=a;i<=n;i++)
#define PER(i,a,n) for (int i=n;i>=a;i--)
#define MEM(a,b) memset(a,b,sizeof(a))
#define PAUSE system("pause")
#define DEBUG
typedef long long ll;
const ll mod=1000000007;

ll N;
int cost[1000010],head[1000010],tot;
ll dp[1000010];
int cir[1000010],fa[1000010];
ll link[2000010],pos=0,mark[1000010];
ll dist[2000010],ans;

struct Edge{
	ll to,nxt;
}edges[1000010];

struct que{
	int front,tail,id[1000010];
	ll s[1000010];
	void push(ll x,int k) {
		while(tail>front&&s[tail-1]<x) tail--;
		s[tail++]=x; 
		id[tail-1]=k;
	}
	void print() {
		REP(m,front,tail) printf("%lld %d ",s[m],id[m]); putchar('\n');
	}
}Q;

inline int read() {
	char ch=getchar(); int re=0; while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') {re=re*10+ch-'0'; ch=getchar();} return re;
}

inline void add(ll from,ll to) {
	edges[++tot].to=to;edges[tot].nxt=head[from];head[from]=tot;
}

void input() {
	N=read();
	int u,c;
	REP(i,1,N) {u=read(),c=read(); 
	add(u,i); cost[i]=c; fa[i]=u;} 
	return;
}

ll dfs(int u) {
	if(dp[u]) return dp[u];
	ll deep=0,out=0;
	for(int p=head[u];p;p=edges[p].nxt) {
		int v=edges[p].to;
		out++;
		if(cir[v]<-1) continue;
		deep=max(deep,dfs(v));
	}
	if(cir[u]<-1&&out==1l) dp[u]=0;else if(cir[u]<-1) dp[u]=deep;else dp[u]=deep+cost[u];
	return dp[u];
}

void solve() {
	MEM(cir,-1);
	ll id=1;
	REP(i,1,N) {
		if(cir[i]==-1) {
			int j=i;
			while(cir[j]!=i) {cir[j]=i;j=fa[j];}
			if(cir[j]==i) {id++;while(cir[j]==i) {cir[j]=-id;j=fa[j];}}
		}
	}
	REP(i,1,N) printf("%d ",cir[i]);
	REP(i,1,N) if(!dp[i]) dfs(i);
	//REP(i,1,N) printf("%lld ",dp[i]);
	REP(i,1,N) {
		if(cir[i]<0&&cir[i]!=-1&&mark[-cir[i]]==0) {
			mark[-cir[i]]=1;
			pos=0;
			int j=i,v=cir[i];
			while(cir[j]==v) {cir[j]=-1;link[++pos]=j;
			dist[pos+1]=dist[pos]+cost[j];j=fa[j];}
			REP(v,1,pos) link[v+pos]=link[v];
			REP(v,pos+1,2*pos) dist[v+1]=dist[v]+cost[link[v-pos]];
			//REP(m,1,pos*2) printf("\n%lld",link[m]);
			//REP(m,1,pos*2+1) printf("\n%lld",dist[m]);
			REP(m,1,pos*2+1) Q.s[i]=0,Q.id[i]=0;
			ll res=0;
			j=1;
			Q.front=Q.tail=0;
			REP(x,1,pos*2) {
				while(j-x+1<=pos&&j<=pos*2) {ll t=dp[link[j]]+dist[j]-dist[x];Q.push(t,j),j++;/*Q.print();*/}
				while(Q.id[Q.front]-x+1>pos&&Q.front<Q.tail) Q.front++;
 				if(Q.front<Q.tail&&Q.id[Q.front]+1-x==pos) {res=max(res,dist[Q.id[Q.front]]-dist[x]+dp[link[x]]+dp[link[Q.id[Q.front]]]);Q.front++;}
				if(Q.id[Q.front]+1-x<=pos&&res<dist[Q.id[Q.front]]-dist[x]+dp[link[x]]+dp[link[Q.id[Q.front]]]) {res=dist[Q.id[Q.front]]-dist[x]+dp[link[x]]+dp[link[Q.id[Q.front]]];}
			}
			ans+=res;
		}
	}
	return;
}

int main() {
	#ifdef FILE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	input();
	solve();
	printf("%lld",ans);
	PAUSE;
	return 0;
}
