#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
using namespace std;
int n;
int v[100002];
int s[100002];
int e[100002];
__int64 sum[100002];
__int64 ans = -1;
int S, E;
int  main()
{
  freopen("TEXT.txt","r",stdin); 
  scanf("%d", &n);
  int i, j;
  v[0] = -1;
  v[n + 1] = -1;
  for(i = 1; i <= n; i ++)
  {
   scanf("%d", v + i);
   for(j = i - 1; j >= 0; )
   {
    if(v[i] > v[j])
    {
     s[i] = j + 1;
     break;
    }
    else
    {
     j = s[j] - 1;
    }
   }
  }
  for(i = n; i >= 1; i --)
  {
   for(j = i + 1; j <= n + 1; )
   {
    if(v[i] > v[j])
    {
     e[i] = j - 1;
     break;
    }
    else
    {
                 j = e[j] + 1;
    }
   }        
  }
  __int64 tsum = 0;
  sum[0] = 0;
     for(i = 1; i <= n; i ++)
  {
   sum[i] = sum[i-1] + v[i];
  }
  __int64 tans;
  for(i = 1; i <= n; i ++)
  {
         tans = (sum[e[i]] - sum[s[i] - 1])*v[i];
   if(tans > ans)
   {
    ans = tans;
    S = s[i];
    E = e[i];
   }
  }
  printf("%I64d\n", ans);
  printf("%d %d\n", S, E);  
  return 0;  
}
