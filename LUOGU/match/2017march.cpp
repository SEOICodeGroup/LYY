#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int N,next[100010],fa[100010];
long long ans;
struct edge{
    int from,to,cost;
}e[100010];

bool cmp(edge a,edge b) {
    return a.cost>b.cost;
}

int find(int x) {
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    scanf("%d",&N);
    for(int i=1;i<=N;i++) {
        e[i].from=i;
        scanf("%d%d",&e[i].to,&e[i].cost);
    }
    for(int i=1;i<=N;i++) fa[i]=i;
    sort(e+1,e+1+N,cmp);
    for(int i=1;i<=N;i++) {
        int fx=find(e[i].to),fy=find(e[i].from);
        printf("%d %d\n",fx,fy);
        if(fx!=fy) fa[e[i].to]=fy;
        else {
            ans+=e[i].cost;
        }
    }
    system("pause");
    printf("%lld\n",ans);
    return 0;
}