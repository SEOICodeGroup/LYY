    #include<iostream>  
    #include<cstdio>  
    #include<cstring>  
    using namespace std;  
    const int maxm = 1e5+5;  
    struct node  
    {  
        long long l, r;  
        node() {}  
        node(long long ll, long long rr): l(ll), r(rr) {}  
    }res[maxm];  
      
    int main(void)  
    {  
        long long n;  
        while(cin >> n)  
        {  
            long long s = 1, e = 1, ans = 0;  
            long long sum =  0;  
            while(1)  
            {  
                while(e*e <= n && sum < n)  
                    sum += e*e, e++;  
                if(sum < n) break;  
                if(sum == n) res[ans++] = node(s, e);  
                sum -= s*s, s++;  
            }  
            printf("%lld\n", ans);  
            for(int i = 0; i < ans; i++)  
            {  
                printf("%d", res[i].r - res[i].l);  
                for(int j = res[i].l; j < res[i].r; j++)  
                    printf(" %d", j);  
                printf("\n");  
            }  
        }  
        return 0;  
    }  
