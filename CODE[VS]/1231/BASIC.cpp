#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct edge {int u,v,cost;};




bool cmp(const edge &a,const edge &b)
{
	return a.cost < b.cost;
}

const int MAX = 100000 + 5;
edge es[MAX];
int set[MAX];
int V,E;
long long ans= 0;
int find(int x)
{
    return x == set[x] ? x : set[x] = find(set[x]);
}

void Kruskal()
{
	sort(es,es+E,cmp);
	for(int i = 1; i <= V ;i++) set[i] = i;
	for(int i = 0; i< E; i++)
	{
		edge e = es[i];
		int sew1 = find(e.u), sew2 = find(e.v);
		if(sew1!=sew2)
		{
			ans += e.cost;
			set[sew1] = sew2;
		}
	}
}

int main()
{
	cin >> V >> E;
	for(int i = 0; i < E; i++)
	{
		cin >> es[i].u >> es[i].v >> es[i].cost;
		
	}
Kruskal();
	cout << ans;
	return 0;
}
