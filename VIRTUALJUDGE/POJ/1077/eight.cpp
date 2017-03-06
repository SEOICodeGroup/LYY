#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#define prime 1000003
using namespace std;
int depth, vis[10][5], ok;
struct sit{int hash;char f;};
vector<sit> h[1000004];
queue<int> q1;
queue<int> q2;
vector<char> ans;
int Hash(int d[][4]) {
	int hash = 0;
	for (int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) {
			hash = hash * 10 + d[i][j];
		}
	}
	return hash;
}
bool find(int x) {
	int temp = x % prime;
	for(int i = 0; i < h[temp].size(); i ++) {
		if(x == h[temp][i].hash) return true;
	}
	return false;
}
int d[4][4];
void print_pre(int m, int n) {
    int x = Hash(d);
    int temp = x % prime, k = 0;
    for (int i = 0; i < h[temp].size(); i ++)
        if(h[temp][i].hash == x) {k = i; break;}
    char fhash = h[temp][k].f;
    if (fhash == 's') {
        return ;
    } else if(fhash == 'u') {
        swap(d[m][n], d[m + 1][n]);
        print_pre(m + 1, n);
    } else if(fhash == 'd') {
        swap(d[m][n], d[m - 1][n]);
        print_pre(m - 1, n);
    } else if (fhash == 'l') {
        swap(d[m][n], d[m][n + 1]);
        print_pre(m, n + 1);
    } else {
        swap(d[m][n], d[m][n - 1]);
        print_pre(m, n - 1);
    }
    putchar(fhash);
}

void print_post(int m, int n) {
    int x = Hash(d);
    int temp = x % prime, k = 0;
    for (int i = 0; i < h[temp].size(); i ++)
        if(h[temp][i].hash == x) {k = i; break;}
    char fhash = h[temp][k].f;
    putchar(fhash);
    if (fhash == 'e') {
        return ;
    } else if(fhash == 'u') {
        swap(d[m][n], d[m + 1][n]);
        print_post(m + 1, n);
    } else if(fhash == 'd') {
        swap(d[m][n], d[m - 1][n]);
        print_post(m - 1, n);
    } else if (fhash == 'l') {
        swap(d[m][n], d[m][n + 1]);
        print_post(m, n + 1);
    } else {
        swap(d[m][n], d[m][n - 1]);
        print_post(m, n - 1);
    }
}
void print(int x) {
    int m, n, t = 10;
    int e[4][4];
    for(int i = 3; i >= 1; i --) {
        for(int j = 3; j >= 1; j --){
            e[i][j] = x % t;
            x /= t;
            if(e[i][j] == 9) m = i, n = j;
        }
    }
    memcpy(d, e, sizeof(int) * 16);
	print_pre(m, n);
	memcpy(d, e, sizeof(int) * 16);
	print_post(m, n);
}
int insh(int d[][4], char f) {
	int hash = Hash(d);
	int tem = hash % prime;
	sit temp ;
	temp.hash = hash;
	temp.f = f;
	h[tem].push_back(temp);
	if(find(hash)) {print(hash); return 0;}
	return hash;
}
void insq(int d[4][4],int v,int m, int n) {
	int e[4][4];
	if (v == 1) {
		if(m - 1 >= 1 && !vis[(m - 1) * 3 + n][0]) {
			memcpy(e, d, sizeof(*d) * 4);
			swap(e[m][n], e[m - 1][n]);
			int temp = insh(e, 'u');
			if(temp == 0) {ok = true; return ;} else q1.push(temp);
			vis[(m - 1) * 3 + n][0] = 1;
		}
		if(m + 1 <= 3 && !vis[(m - 1) * 3 + n][1]) {
			memcpy(e, d, sizeof(*d) * 4);
			swap(e[m][n], e[m + 1][n]);
			int temp = insh(e, 'd');
			if(temp == 0) {ok = true; return ;} else q1.push(temp);
			vis[(m - 1) * 3 + n][1] = 1;
		}
		if(n - 1 >= 1 && !vis[(m - 1) * 3 + n][2]) {
			memcpy(e, d, sizeof(*d) * 4);
			swap(e[m][n], e[m][n - 1]);
			int temp = insh(e, 'l');
			if(temp == 0) {ok = true; return ;} else q1.push(temp);
			vis[(m - 1) * 3 + n][2] = 1;
		}
		if(n + 1 <= 3 && !vis[(m - 1) * 3 + n][3]) {
			memcpy(e, d, sizeof(*d) * 4);
			swap(e[m][n], e[m][n + 1]);
			int temp = insh(e, 'r');
			if(temp == 0) {ok = true; return ;} else q1.push(temp);
			vis[(m - 1) * 3 + n][3] = 1;
		}
	}
	if (v == 2) {
		if(m - 1 >= 1 && !vis[(m - 1) * 3 + n][0]) {
			memcpy(e, d, sizeof(*d) * 4);
			swap(e[m][n], e[m - 1][n]);
			int temp = insh(e, 'u');
			if(temp == 0) {ok = true; return ;} else q2.push(temp);
			vis[(m - 1) * 3 + n][0] = 1;
		}
		if(m + 1 <= 3 && !vis[(m - 1) * 3 + n][1]) {
			memcpy(e, d, sizeof(*d) * 4);
			swap(e[m][n], e[m + 1][n]);
			int temp = insh(e, 'd');
			if(temp == 0) {ok = true; return ;} else q2.push(temp);
			vis[(m - 1) * 3 + n][1] = 1;
		}
		if(n - 1 >= 1 && !vis[(m - 1) * 3 + n][2]) {
			memcpy(e, d, sizeof(*d) * 4);
			swap(e[m][n], e[m][n - 1]);
			int temp = insh(e, 'l');
			if(temp == 0) {ok = true; return ;} else q2.push(temp);
			vis[(m - 1) * 3 + n][2] = 1;
		}
		if(n + 1 <= 3 && !vis[(m - 1) * 3 + n][3]) {
			memcpy(e, d, sizeof(*d) * 4);
			swap(e[m][n], e[m][n + 1]);
			int temp = insh(e, 'r');
			if(temp == 0) {ok = true; return ;} else q2.push(temp);
			vis[(m - 1) * 3 + n][3]= 1;
		}
	}
}
void bfs() {
	ok = 0;
	while(!q1.empty() && !q2.empty()) {
		int x = q1.front(); q1.pop(); int t = 10;
		int e[4][4], m, n;
		for(int i = 3; i >= 1; i --) {
			for(int j = 3; j >= 1; j --){
				e[i][j] = x % t;
				x /= t;
				if(e[i][j] == 9) m = i, n = j;
			}
		}
		insq(e, 1, m, n);
		if(ok) return;
		int y = q2.front(); q2.pop();
		for(int i = 3; i >= 1; i --) {
			for(int j = 3; j >= 1; j --){
				e[i][j] = y % t;
				y /= t;
				if(e[i][j] == 9) m = i, n = j;
			}
		}
		insq(e, 2, m, n);
		if(ok) return;
	}
}
int main() {
	int m, n;
	char e[4][4];
	for(int i = 1; i <= 3; i ++) {
		for (int j = 1; j <= 3; j ++) {
			scanf("%s",&e[i][j]);
			if(e[i][j] == 'x') m = i, n = j, e[i][j] = 9;
			else e[i][j] -= '0';
		}
	}
	int k[4][4], t[4][4];
	for(int i = 1; i <= 3 ; i ++)
		for(int j = 1; j <= 3; j ++) k[i][j] = int(e[i][j]), t[i][j] = (i - 1) * 3 + j;
	q1.push(insh(k, 's'));
	q2.push(insh(t, 'e'));
	bfs();
	return 0;
}
