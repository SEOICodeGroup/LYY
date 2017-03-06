#include <iostream> 
#include <algorithm> 
#include <cstdio>
#include <cstring> 
#include <cmath>

using namespace std;

int n,a[200],tot;
int main(){
ios::sync_with_stdio(false);
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++){
//当前的数字为a[i]
for(int j=1;j<=n;j++){
if(j==i)continue;
for(int k=1;k<=n;k++){
if(k==i||k==j)continue;
if(a[i]==a[j]+a[k]){
tot++;
goto die;
}
}
}
die:;
}
cout<<tot<<endl;
}
