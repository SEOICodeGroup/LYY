#include <cstdio>
using namespace std;
int s[205];
int main() {
    freopen("test.txt","w",stdout);
    int a=1237,b=1507;
    int T=200;
    s[1]=17;
    for(int i=2;i<=T;i++) {
        s[i]=(s[i-1]*a+b)%10001;
    }
    for(int i=1;i<=T;i++) if(i&1) printf("%d ",s[i]);
    for(int i=1;i<=T;i++) printf("\n%d",s[i]);
}