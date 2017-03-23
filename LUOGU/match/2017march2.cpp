#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
int N;
int s[100];
int a[100],tmp[100];
int ans; 
int f[100],pos;
void Merge(int l,int m,int r)  
{  
    int i = l;  
    int j = m + 1;  
    int k = l;  
    while(i <= m && j <= r)  
    {  
        if(a[i] > a[j])  
        {  
            tmp[k++] = a[j++];  
            ans += m - i + 1;  
        }  
        else  
        {  
            tmp[k++] = a[i++];  
        }  
    }  
    while(i <= m) tmp[k++] = a[i++];  
    while(j <= r) tmp[k++] = a[j++];  
    for(int i=l;i<=r;i++)  
        a[i] = tmp[i];  
}  
void Merge_sort(int l,int r)  
{  
    if(l < r)  
    {  
        int m = (l + r) >> 1;  
        Merge_sort(l,m);  
        Merge_sort(m+1,r);  
        Merge(l,m,r);  
    }  
}  //1 5 19 97 601
int main() {
    cin>>N;
    int k=0;pos=1;int mx=-1;
    for(int i=1;i<=N;i++) s[i]=i;
    do{
        //cout<<k++<<endl;
        ans=0;k++;
        for(int i=1;i<=N;i++) a[i]=s[i];
        Merge_sort(1,N);
        if(ans==4){mx=ans;cout<<k<<":";for(int i=1;i<=N;i++) printf("%d ",s[i]);cout<<endl;}
        /*for(int i=1;i<=10;i++) {
            cout<<i<<":";
            int k=0;
            for(int j=1;j<=pos;j++) {if(f[j]==i) k++;}
            cout<<k<<endl;*/
    }while (next_permutation(s+1,s+1+N)); 
        system("pause");
}
//30
/*
1 2 3 4 5 6 7 8 9 10
1 2 3 4 5 6 7 8 10 9
1 2 3 4 5 6 7 9 10 8
1 2 3 4 5 6 7 10 9 8
1 2 3 4 5 6 8 10 9 7
1 2 3 4 5 6 9 10 8 7
1 2 3 4 5 6 10 9 8 7
1 2 3 4 5 7 10 9 8 6
1 2 3 4 5 8 10 9 7 6
1 2 3 4 5 9 10 8 7 6
1 2 3 4 5 10 9 8 7 6
1 2 3 4 6 10 9 8 7 5
1 2 3 4 7 10 9 8 6 5
1 2 3 4 8 10 9 7 6 5
1 2 3 4 9 10 8 7 6 5
1 2 3 4 10 9 8 7 6 5
1 2 3 5 10 9 8 7 6 4
1 2 3 6 10 9 8 7 5 4
1 2 3 7 10 9 8 6 5 4
1 2 3 8 10 9 7 6 5 4
*/