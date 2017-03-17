#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

char str[500100],s[1000010];
int N,len,f[1000010],m[1000010];
set<int> ss;

void manacher() {
    len=N;
    int p=0,mx=0;
    for (int i=0;i<len;i++) {
        if (mx>i) f[i]=min(f[2*p-i],mx-i);
        else f[i]=0;
        while(i+f[i]+1<len&&i-f[i]>=0&&s[i+f[i]+1]==s[i-f[i]]) f[i]++;
        //printf("%d ",f[i]);
        if (f[i]+i>mx) mx=f[i]+i,p=i;
    }
    return;
}
//ggabaabaabaaball
bool cmp(int a,int b) {
    return (a-f[a])<(b-f[b]);
}
int main() {
    scanf("%d",&N);
    scanf("%s",s);
    manacher();
    for(int i=0;i<N;i++) m[i]=i;
    sort(m,m+N,cmp);
    int res=0,now=0;
    for(int i=0;i<N;i++) {
        while(now<N&&m[now]-f[m[now]]<=i) {
            ss.insert(m[now]);
            now++;
        }   
        set<int>::iterator tem=ss.upper_bound(i+f[i]/2);
        if(tem!=ss.begin()) {
            res=max(res,(*--tem-i)*4);
        }

    }
    printf("%d\n",res);
    system("pause");
    return 0;
}
