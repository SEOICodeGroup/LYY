#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define REP(i,a,n) for (int i=a;i<=n;i++)
#define PER(i,a,n) for (int i=n;i>=a;i--)
using namespace std;
int n,f[209][209]={0},s[209],ans=0;
int maxn(int a,int b){if(a>b){return a;}else{return b;}}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){cin>>s[i];s[i+n]=s[i];}
    for(int i=n*2-1;i>=1;i--)
    {
        for(int j=i+1;j<n*2&&j-i<n;j++)
        {
            for(int k=i;k<j;k++)
            {
                f[i][j]=maxn(f[i][j],f[i][k]+f[k+1][j]+s[i]*s[k+1]*s[j+1]);
            }
            ans=maxn(ans,f[i][j]);
        }
    }
    REP(i,1,2*n) REP(j,1,2*n) printf("%d %d %d\n",i,j,f[i][j]);
    cout<<ans;
    system("pause");
    return 0;
}