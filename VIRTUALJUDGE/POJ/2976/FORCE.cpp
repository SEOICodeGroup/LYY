
    #include <set>  
    #include <map>  
    #include <queue>  
    #include <math.h>  
    #include <vector>  
    #include <string>  
    #include <stdio.h>  
    #include <string.h>  
    #include <stdlib.h>  
    #include <iostream>  
    #include <algorithm>  
      
    #define eps 1e-7  
    #define pi acos(-1.0)  
    #define inf 107374182  
    #define inf64 1152921504606846976  
    #define lc l,m,tr<<1  
    #define rc m + 1,r,tr<<1|1  
    #define iabs(x)  ((x) > 0 ? (x) : -(x))  
    #define clear1(A, X, SIZE) memset(A, X, sizeof(A[0]) * (SIZE))  
    #define clearall(A, X) memset(A, X, sizeof(A))  
    #define memcopy1(A , X, SIZE) memcpy(A , X ,sizeof(X[0])*(SIZE))  
    #define memcopyall(A, X) memcpy(A , X ,sizeof(X))  
    #define max( x, y )  ( ((x) > (y)) ? (x) : (y) )  
    #define min( x, y )  ( ((x) < (y)) ? (x) : (y) )  
      
    using namespace std;  
      
    int n,k;  
    double a[1005],b[1005],t[1005];  
      
    double does(double num)  
    {  
        for(int i=0;i<n;i++)  
        {  
            t[i]=a[i]-num*b[i];  
        }  
        sort(t,t+n);  
        double sum=0.0;  
        for(int i=k;i<n;i++)  
        {  
            sum+=t[i];  
        }  
        return sum;  
    }  
      
    int main()  
    {  
        while(scanf("%d%d",&n,&k),n||k)  
        {  
            for(int i=0;i<n;i++)  
            {  
                scanf("%lf",&a[i]);  
            }  
            for(int i=0;i<n;i++)  
            {  
                scanf("%lf",&b[i]);  
            }  
            double l=0.0,r=1.0,mid;  
            while(r-l>eps)  
            {  
                mid=(l+r)/2;  
                if(does(mid)>0)l=mid;  
                else r=mid;  
            }  
            printf("%.0f\n",l*100);  
        }  
        return 0;  
    }  
