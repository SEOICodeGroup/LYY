#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;
int f[maxn],len1,pre[maxn*2],suf[maxn*2],len;
char txt[maxn],s[maxn*2];
void Manacher(){
    for(int i=0;i<len1;i++){
        s[i<<1]='@';
        s[(i<<1)+1]=txt[i];
    }
    s[(len1)<<1]='@';
    len=2*len1+1;
    int mx=0,p=0;
    for(int i=0;i<len;i++){
        if(mx>i) f[i]=min(mx-i,f[2*p-i]);
        else f[i]=0;
        while(i+f[i]+1<len&&i-f[i]-1>=0&&s[i+f[i]+1]==s[i-f[i]-1]) f[i]++;
        if(f[i]+i>mx){
            mx=f[i]+i;
            p=i;
        }
    }
    return;
}