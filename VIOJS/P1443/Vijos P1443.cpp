#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;
//Product by MiracleEEEE
int setsum[30010];
struct setunit {
 	int dep, set;
 }sets[30010]; 
inline int read() {
	char ch = getchar(); int re = 0; while (ch<'0' || ch>'9') ch=getchar();  
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return re;
}
inline void write(int re) {
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
int find (int x) { 
	//printf("%d %d\n",x, sets[x].set );
	if(sets[x].set != x) {
		int temp1 = sets[x].set;
		int temp2 = find(sets[x].set);
		sets[x].dep += sets[temp1].dep - sets[temp2].dep;
		//printf("sets[%d].dep = %d\n",x, sets[x].dep);
		sets[x].set = temp2;
	}
	return sets[x].set;
} 
void check(int x, int y) {
	int fx = find(x), fy = find(y);
	//printf(" set[%d].dep = %d .set = %d set[%d].dep = %d .set = %d\n",x, sets[x].dep,sets[x].set, y, sets[y].dep,sets[y].set);
	if (fx != fy){
		printf("-1\n");
	} else {
		printf("%d\n",abs(sets[x].dep - sets[y].dep) - 1 );
	}
}
void Union(int x, int y) {
	int fx = find(x), fy = find(y);
	sets[fx].set = fy;
	sets[fx].dep += setsum[fy];
	setsum[fy] += setsum[fx];
}
bool solve() {
	for (int i = 1; i <= 30010; i ++) {setsum[i] = 1; sets[i].dep = 1;sets[i].set = i;}
	int T = read();
	while (T --) {
		char S; scanf("%c",&S);
		int a, b;			
		a = read(), b = read();
		if (S == 'M') {
			Union(a, b);
		} else {
			check(a, b); 
		}
	}
	return true;
}
int main() {
	solve();
	return 0;
} 
