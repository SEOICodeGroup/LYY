#include <cstdio>
#include <iostream>
#include <cassert>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,a,n) for (int i=a;i<=n;i++)
#define PER(i,a,n) for (int i=n;i>=a;i--)
#define MEM(a,b) memset(a,b,sizeof(a))
#define PAUSE system("pause")
#define FILE
#define DEBUG
typedef long long ll;
const ll mod=1000000007;
const ll maxn=200000;
const ll mine=9223372036854775808;
ll M,D,t,s,len,res;
inline int getc() {
    static const int L=1<<15;static char buf[L],*S=buf,*T=buf;
    if(S==T) {T=(S=buf)+fread(buf,1,L,stdin);if(S==T) return EOF;}
    return *S++;
}
inline int read() {
    int c; while(!isdigit(c=getc())); int tem=c-'0';
    while(isdigit(c=getc())) tem=(tem<<1)+(tem<<3)+c-'0';
    return tem;
}

struct Node {
        int l,r,m;
        ll mx;
        Node* son[2];
}*root;
Node fre[(maxn<<2)+5];
int fretop;
Node* Get() {
        return &fre[fretop++];
}

void build(Node *o,int l,int r) {
        int m=(l+r)>>1;
        o->l=l,o->r=r,o->m=m,o->mx=mine;
        if(l==r) return;
        build(o->son[0]=Get(),l,m);
        build(o->son[1]=Get(),m+1,r);

}
void modify(Node *o,ll pos) {
        if(o->l==pos&&o->r==pos) {o->mx=s;return;}
        if(pos<=o->m) modify(o->son[0],pos);
        if(pos>o->m) modify(o->son[1],pos);
        o->mx=max(o->son[0]->mx,o->son[1]->mx);
        return;
}
void query(Node *o,int L,int R) {
        if(o->l>=L&&o->r<=R) {res=max(res,o->mx);return;}
        if(L<=o->m) query(o->son[0],L,R);
        if(R>o->m) query(o->son[1],L,R);
        return;
}
void input() {
        scanf("%lld%lld",&M,&D);
        root=Get();
        build(root,1,maxn);
        return;
}
void solve() {
        t=0l,len=0l;
        REP (i,1,M) {
                char c[2];
                scanf("%s",c);
                if (c[0]=='A') {
                        scanf("%lld",&s);
                        s=(s+t)%D;
                        modify(root,++len);
                } else {
                        scanf("%lld",&s);
                        res=mine;
                        query(root,len-s+1,len);
                        t=res;
                        printf("%lld\n",res);
                }
        }
}
int main() {
	#ifdef FILE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	input();
	solve();
	return 0;
}
