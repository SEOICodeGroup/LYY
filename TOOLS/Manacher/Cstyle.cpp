#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int maxn=100;
int f[maxn],len1,pre[maxn*2],suf[maxn*2],len;
char txt[maxn],s[maxn*2];
void Manacher() {
    for (int i=0;i<len1;i++) {
        s[i<<1]='#';
        s[i<<1|1]=txt[i];
    }
    s[len1<<1]='#';     //分割字符串
    len=2*len1+1;
    int mx=0,p=0;
    for (int i=0;i<len;i++) {
        if(mx>i) f[i]=min(mx-1,f[2*p-i]);   //2*p-1为i关于pos的对称点
        else f[i]=0;
        while(i+f[i]+1<len&&i-f[i]-1>=0&&s[i+f[i]+1]==s[i-f[i]-1]) f[i]++;
        if(f[i]+i>mx) mx=f[i]+i,p=i;
    }
    for (int i=0;i<len;i++) {
        if(i&1) f[i]=((f[i]>>1)<<1)+1;
        else f[i]=((f[i]>>1)<<1);
    }
    return;
}

int main() {
    scanf("%s",txt);
    len1=strlen(txt);
    Manacher();
    for(int i=0;i<len;i++) printf("%d ",f[i]);
    system("pause");
    return 0;
}