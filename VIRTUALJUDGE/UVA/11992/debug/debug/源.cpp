#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <cstdlib>  
#include <iostream>  
#include <algorithm>  
#include <vector>  
#include <map>  
#include <queue>  
#include <stack>  
using namespace std;

const int maxn = 1e6 + 10;
struct node {
	int l, r, addv, setv, maxv, minv, sum;
}e[maxn * 4];
void build(int a, int b, int c)
{
	e[c].l = a;
	e[c].r = b;
	e[c].addv = e[c].setv = e[c].maxv = e[c].minv = e[c].sum = 0;
	if (a == b)return;
	int mid = (a + b) / 2;
	build(a, mid, 2 * c);
	build(mid + 1, b, 2 * c + 1);
}
void pushdown(int c)
{
	if (e[c].setv != 0)
	{
		e[2 * c].addv = e[2 * c + 1].addv = 0;
		e[2 * c].setv = e[2 * c + 1].setv = e[c].setv;
		e[2 * c].maxv = e[2 * c + 1].maxv = e[c].setv;
		e[2 * c].minv = e[2 * c + 1].minv = e[c].setv;
		e[2 * c].sum = (e[2 * c].r - e[2 * c].l + 1)*e[c].setv;
		e[2 * c + 1].sum = (e[2 * c + 1].r - e[2 * c + 1].l + 1)*e[c].setv;
		e[c].setv = 0;
	}
	if (e[c].addv != 0)
	{
		e[2 * c].addv += e[c].addv; e[2 * c + 1].addv += e[c].addv;
		e[2 * c].maxv += e[c].addv; e[2 * c + 1].maxv += e[c].addv;
		e[2 * c].minv += e[c].addv; e[2 * c + 1].minv += e[c].addv;
		e[2 * c].sum += (e[2 * c].r - e[2 * c].l + 1)*e[c].addv;
		e[2 * c + 1].sum += (e[2 * c + 1].r - e[2 * c + 1].l + 1)*e[c].addv;
		e[c].addv = 0;
	}
}
void add(int a, int b, int c, int val)
{
	//printf("%d\n",c);  
	if (e[c].l == a&&e[c].r == b)
	{
		e[c].addv += val;
		e[c].maxv += val;
		e[c].minv += val;
		e[c].sum += (b - a + 1)*val;
		return;
	}
	int mid = (e[c].l + e[c].r) / 2;
	pushdown(c);
	if (b <= mid)add(a, b, 2 * c, val);
	else if (a>mid)add(a, b, 2 * c + 1, val);
	else
	{
		add(a, mid, 2 * c, val);
		add(mid + 1, b, 2 * c + 1, val);
	}
	e[c].maxv = max(e[2 * c].maxv, e[2 * c + 1].maxv);
	e[c].minv = min(e[2 * c].minv, e[2 * c + 1].minv);
	e[c].sum = e[2 * c].sum + e[2 * c + 1].sum;
}
void update(int a, int b, int c, int val)
{
	if (e[c].l == a&&e[c].r == b)
	{
		e[c].addv = 0;
		e[c].setv = val;
		e[c].maxv = val;
		e[c].minv = val;
		e[c].sum = (b - a + 1)*val;
		return;
	}
	pushdown(c);
	int mid = (e[c].l + e[c].r) / 2;
	if (b <= mid)update(a, b, 2 * c, val);
	else if (a>mid)update(a, b, 2 * c + 1, val);
	else
	{
		update(a, mid, 2 * c, val);
		update(mid + 1, b, 2 * c + 1, val);
	}
	e[c].maxv = max(e[2 * c].maxv, e[2 * c + 1].maxv);
	e[c].minv = min(e[2 * c].minv, e[2 * c + 1].minv);
	e[c].sum = e[2 * c].sum + e[2 * c + 1].sum;
}
node query(int a, int b, int c)
{
	if (e[c].l == a&&e[c].r == b)return e[c];
	pushdown(c);
	int mid = (e[c].l + e[c].r) / 2;
	if (b <= mid)return query(a, b, 2 * c);
	else if (a>mid)return query(a, b, 2 * c + 1);
	else
	{
		node o, p, q;
		p = query(a, mid, 2 * c);
		q = query(mid + 1, b, 2 * c + 1);
		o.sum = p.sum + q.sum;
		o.maxv = max(p.maxv, q.maxv);
		o.minv = min(p.minv, q.minv);
		return o;
	}
}
int main()
{
	freopen("TEXT.txt", "r", stdin);
	freopen("OUTPUT.txt", "w", stdout);
	int r, c, m;
	while (scanf("%d%d%d", &r, &c, &m) != EOF)
	{
		int i, j, k, a, x1, y1, x2, y2, val;
		build(1, r*c, 1);
		for (i = 0; i<m; i++)
		{
			scanf("%d", &a);
			if (a == 1)
			{
				scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &val);
				//printf("*\n");  
				for (j = x1; j <= x2; j++)
					add((j - 1)*c + y1, (j - 1)*c + y2, 1, val);
			}
			else if (a == 2)
			{
				scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &val);
				for (j = x1; j <= x2; j++)
					update((j - 1)*c + y1, (j - 1)*c + y2, 1, val);
			}
			else
			{
				node ans, p;
				scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
				for (j = x1; j <= x2; j++)
				{
					if (j == x1)ans = query((j - 1)*c + y1, (j - 1)*c + y2, 1);
					else
					{
						p = query((j - 1)*c + y1, (j - 1)*c + y2, 1);
						ans.sum += p.sum;
						ans.maxv = max(ans.maxv, p.maxv);
						ans.minv = min(ans.minv, p.minv);
					}
				}
				printf("%d %d %d\n", ans.sum, ans.minv, ans.maxv);
			}
		}
	}
	return 0;
}