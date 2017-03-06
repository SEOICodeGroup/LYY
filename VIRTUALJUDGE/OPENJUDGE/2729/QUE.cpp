#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
int N,K,P;
cin>>N>>K>>P;
queue<int> q;
int a[50000];
for(int i=0;i<K;i++)
q.push(i+1);
int pla=0,times=0;
while(q.size()>0){
pla++;
if(pla%N==0){
a[(pla-N)/N]=q.front();
q.pop();//
times++;
}
else
q.pop();
for(int j=0;j<P;j++){
q.push(q.front());
q.pop();
}
}
sort(a+0,a+times);
for(int i=0;i<times;i++)
cout<<a[i]<<"\n";
//system("PAUSE");
return 0;
}
