#include<set>  
#include<map>  
#include<list>  
#include<queue>  
#include<stack>  
#include<string>  
#include<math.h>  
#include<time.h>  
#include<vector>  
#include<bitset>  
#include<memory>  
#include<utility>  
#include<stdio.h>  
#include<sstream>  
#include<iostream>  
#include<stdlib.h>  
#include<string.h>  
#include<algorithm> 
#define LL unsigned long long  
using namespace std;
int b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z;
int pd[500][500],a[500][500];
int wh[500];
int main()
{
    scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        {
            a[i][j]=233333333;//��ʼ�� 
        }
    for (i=1;i<=n;i++)
    {
        scanf("%d",&wh[i]);
    }
    for (i=1;i<=k;i++)
        for (j=1;j<=k;j++)
        {
            scanf("%d",&pd[i][j]);
        }
    for (i=1;i<=m;i++)
    {
        scanf("%d %d %d",&x,&y,&z);
        if (z<a[x][y])//������֮�䲻ֹһ����·������Ҫ���ж� 
        {
            if (pd[wh[x]][wh[y]]==0) a[y][x]=z;
            if (pd[wh[y]][wh[x]]==0) a[x][y]=z;  
        }
    }
    for (k=1;k<=n;k++)
        for (i=1;i<=n;i++)
            for (j=1;j<=n;j++)
            if (a[i][k]+a[k][j]<a[i][j]) a[i][j]=a[i][k]+a[k][j];
    if (a[s][t]==233333333) cout<<-1; else cout<<a[s][t];
    return 0;
}
