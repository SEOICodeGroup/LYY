#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#include <cctype>
#include <iostream>
#define N 1050000
using namespace std;
typedef long long ll;
inline int getc() {
    static const int L=1<<15; static char buf[L],*S=buf,*T=buf;
    if(S==T) {T=(S=buf)+fread(buf,1,L,stdin);if(S==T) return EOF;}
    return *S++;
}
inline int read() {
    int c; while(!isdigit(c=getc())); int tem=c-'0';
    while(isdigit(c=getc())) tem=(tem<<1)+(tem<<3)+c-'0';
    return tem;
}
struct Edge {
    int u,v,len,nxt;
}e[N];
struct Tag {
    int edge,flag1,flag2;
    ll temp,max1,max2;
}s[N];
int head[N],cnt,n;
int vis[N],nxt[N],len[N];
int i,j,k;
ll sa[N],pre[N],ans;
void add(int u,int v,int len) {
    cnt++; e[cnt].u=u; e[cnt].v=v;
    e[cnt].len=len; e[cnt].nxt=head[u];
    head[u]=cnt;
}
int que[N<<1];
ll sum[N<<1],ret;
ll dp(int num) {
    int top,tail,u,b,star;
    int et;
    for(et=1;et<(num<<1);et++) sum[et]=sum[et-1]+pre[(et-1)>=num?(et-1-num):(et-1)];
    top=tail=0;
    que[tail++]=0;
    for(et=1;et<(num<<1);++et) {
        while(top<tail&&et-que[top]>=num) ++top;
        u=que[top];
        ret=max(ret,sa[et>=num?et-num:et]+sa[u>=num?u-num:u]+sum[et]-sum[u]);
        while(top<tail&&sa[et>=num?et-num:et]>=sa[que[tail-1]>=num?que[tail-1]-num:que[tail-1]]+sum[et]-sum[que[tail-1]])--tail;
        que[tail++]=et;
    }
    return ret;
}
void build() {
    cnt=1;
    memset(head,0,sizeof(head));
    memset(vis,0,sizeof(vis));
    n=read();
    for(i=1;i<=n;i++) {
        nxt[i]=read();
        len[i]=read();
        add(nxt[i],i,len[i]);
    }
}
stack<int>sk;
int fa[N];
void dfs(int x) {
    if(s[x].edge==0) {
        sk.pop();
        if(s[x].flag2) ret=max(ret,s[x].max1+s[x].max2);
        if(vis[x]==-1) return;
        x=sk.top(); {
            int v,tt=s[x].edge;
            v=e[tt].v;
            vis[v]=i;
            s[x].temp=s[v].max1+e[tt].len;
            if(s[x].max1<s[x].temp) {
                if(s[x].flag1) s[x].max2=s[x].max1,s[x].flag2=1;
                else s[x].flag1=1;
                s[x].max1=s[x].temp;
            }
            else if(s[x].max2<s[x].temp) s[x].max2=s[x].temp,s[x].flag2=1;
            s[x].edge=e[tt].nxt;
        }
        return;
    }
    int v,tt=s[x].edge;
    v=e[tt].v;
    if(vis[v]==-1) {
        s[x].edge=e[tt].nxt;
        return;
    }
    fa[v]=x;
    s[v].edge=head[v];
    sk.push(v);
}
ll handle(int x) {
    s[x].edge=head[x];
    sk.push(x);
    while(!sk.empty()) {
        dfs(sk.top());
    }
    return s[x].max1;
}
int main() {
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int u,v;
    build();
    for(i=1;i<=n;i++) {
        if(!vis[i]) {
                for(u=i;!vis[u];u=nxt[u]) vis[u]=i;
                if(vis[u]==i) {
                    ret=0;cnt=0;
                    vis[u]=-1;
                    for(v=nxt[u];v!=u;v=nxt[v]){
                        vis[v]=-1;
                    }
                    v=u;
                    do{
                        pre[cnt]=len[v];
                        sa[cnt++]=handle(v);
                        v=nxt[v];
                    }while(v!=u);
                    ans+=dp(cnt);
                }
        }
    }
    cout<<ans;
}
/*
7
3 8
7 2
4 2
1 4
1 9
3 4
2 3

*/
