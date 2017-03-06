#include <cstdio>
using namespace std;
//Product by MiracleEEEE 
int n,q;
long long sum[200010], ans;
struct treeNode {
	int l, r, Lazy;
	long long val;
}SegTree[800010];
inline int read(){
	char ch = getchar(); int re = 0; while (ch<'0' || ch>'9') ch=getchar();  
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return re;
}
inline void write(int re){
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
void build(int k, int l, int r) {
	//printf("%d\n", k);
	SegTree[k].r = r; SegTree[k].l = l;
	if (l == r) {
		SegTree[k].val = sum[r] - sum[l - 1];
		return;
	} else {
		int mid = (l + r) >> 1;
		SegTree[k].val = sum[r] - sum[l - 1];
		build(2 * k, l, mid);
		build(2 * k + 1, mid + 1, r);
	} 
}
void update(int k) {
	SegTree[k].val += (SegTree[k].r - SegTree[k].l + 1) * SegTree[k].Lazy;
	if (SegTree[k].l != SegTree[k].r) {
		SegTree[2 * k].Lazy += SegTree[k].Lazy;
		SegTree[2 * k + 1].Lazy += SegTree[k].Lazy;
	}
	SegTree[k].Lazy = 0;
}
void add(int k, int l, int r, int c) {
	update(k);
	//Bprintf("%d l = %d r = %d reql = %d reqr = %d\n", k, SegTree[k].l, SegTree[k].r, l, r);
	if (SegTree[k].l > r || SegTree[k].r < l) return ;
	if (SegTree[k].l >= l && SegTree[k].r <= r) {
		SegTree[k].val += (SegTree[k].r - SegTree[k].l + 1) * c;
		if ( SegTree[k].l != SegTree[k].r ) {
			SegTree[2 * k].Lazy += c;
			SegTree[2 * k + 1].Lazy += c;
		}
		return ;
	}
	if (SegTree[k].l != SegTree[k].r) {
		add(2 * k, l, r, c);
		add(2 * k + 1, l, r, c);
		SegTree[k].val = SegTree[2 * k].val + SegTree[2 * k + 1].val;
	}
	
}
void query(int k, int l, int r) {
	update(k);
	//printf("%d l = %d r = %d reql = %d reqr = %d\n", k, SegTree[k].l, SegTree[k].r, l, r);
	if (SegTree[k].r < l || SegTree[k].l > r) return ;
	if (SegTree[k].l >= l && SegTree[k].r <= r) {
		ans += SegTree[k].val;
		return ;
	}
	if (SegTree[k].l != SegTree[k].r) {
		query(2 * k, l, r);
		query(2 * k + 1, l, r);
	}
	
}
bool solve(){
	n = read();
	int temp;
	for (int i = 1; i <= n; i ++) {
		temp = read();
		sum[i] = sum[i - 1] + temp;
	}
	build(1, 1, n);
	//for (int i = 1; i <= n; ++i) {printf("%lld ",sum[i]);}
	q = read();
	int f, a, b, c;
	while (q --) {
		f = read();
		if (f == 1) {
			a = read(), b = read(), c = read();
			add(1, a, b, c);
		} else {
			a = read(), b = read();
			ans = 0; query(1,a,b); 
			printf("%lld\n", ans);
		}
	}
	return true;
}
int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	solve();
	return 0;
} 
