#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int n, e, s, t, tot;
long long dist[50005];
struct edge{ int u, to, val;}edges[300005];
inline int read(){
	char ch = getchar(); int re = 0; while (ch<'0' || ch>'9') ch=getchar();  
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return re;
}
void input() {
	n = read(), e = read(), s = read(), t = read();
	for ( int i = 1; i <= e; i ++ ) {
		edges[i].u = read(), edges[i].to = read();int val; cin >> edges[i].val;
	}
}

void solve() {
	memset(dist,0x3F,sizeof(dist));
	dist[s] = 0;
	for ( int i  = 1; i <= n; i ++ ) {
		for ( int j = 1; j <= e; j ++ ) {
			if ( dist[edges[j].to] > dist[edges[j].u] + edges[j].val) 
				dist[edges[j].to] = dist[edges[j].u] + edges[j].val;
		}
	}
	bool flag = 1;
	for ( int i = 1; flag && i <= e;  i ++ ) {
		if ( dist[edges[i].to] > dist[edges[i].u] + edges[i].val)
			{flag  = 0;break;}
	}
	if ( !flag ){ printf("Negative!"); return ;}
	if ( dist[t] == 0x3F3F3F3F3F3F3F3F )printf("-1\n");
	else printf("%d", dist[t]);
}
int main(){
	input();
	solve();
	return 0;
}