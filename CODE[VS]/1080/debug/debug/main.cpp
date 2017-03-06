#include <iostream>
using namespace std;
typedef long long ll;
long long C[200010];
long long n, m;
long long lowbit(long long x) {
	return x & -x;
}
long long  query(long long  x) {
	long long  res = 0;
	while (x > 0) {
		res += C[x]; x -= lowbit(x);
	}
	return res;
}
void add(long long  x, long long  d) {
	while (d <= n) {
		C[d] += x; d += lowbit(d);
	}
}
int main() {
	cin >> n;
	for (long long  i = 1; i <= n; i++) {
		long long  x; cin >> x; add(x, i);
	}
	cin >> m;
	for (long long  i = 1; i <= m; i++) {
		long long  k;
		cin >> k;
		if (k == 1) {
			long long  d, x;
			cin >> d >> x;
			add(x, d);
		}
		else {
			long long  l, r;
			cin >> l >> r;
			printf("%lld\n", query(r) - query(l - 1));
		}
	}
	return 0;
}