#include <cstdio>
using namespace std;
const int maxn=1005;
int dep[maxn];
int Getlca(int u,int v) {
        for(int i=14;i>=0;i--) {
                if(pre[u][i]!=pre[v][i]) {
                        u=pre[u][i];
                        v=pre[v][i];
                }
        }
        return u;
}

int main() {

    return 0;
}