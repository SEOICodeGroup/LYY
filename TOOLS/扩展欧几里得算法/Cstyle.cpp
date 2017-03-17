#include <cstdio>
using namespace std;
typedef long long ll;

ll Extend_Euclid(ll a,ll b,ll &d,ll &x,ll &y) {
    if (!b) {d=a;x=1;y=0;}
    else {Extend_Euclid(b,a%b,d,y,x); y-=x*(a/b);}
}

int main() {

    return 0;
}