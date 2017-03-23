#include <cstdio>
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
const int maxn=10000;
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
inline int lowbit(int x) {return x&-x;}
void update(int x,int d) {
        while (x<maxn) {c[x]+=d;x+=lowbit(x);}
}
//从左往右手动求和
int find_kth(int x) {
        int ans=0,cnt=0,i;
        PER (i,1,20) {
                ans+=(1<<i);
                if (ans>=maxn||cnt+c[ans]>=k) ans-=(1<<i);       //加多了，减回去
                else cnt+=c[ans];
        }
        return ans+1; //求出的ans是累加和，表示的是比k小的数。所以k就是区间第k大数。
}
int main() {
	#ifdef FILE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	return 0;
}
