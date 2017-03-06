#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;
#define p 4880
//Product by MiracleEEEE
int C, G, len[35], w[35];
int dp[25][5000][2];
//dp[i][j] = dp[i-1][] = j
//dp[i][j] = i in left j in right
//dp[i][j] = dp[i-w[n]*len[m]][j]
//         = dp[i][j-w[n]*len[m]]
inline int read(){
	char ch = getchar(); int re = 0; while (ch<'0' || ch>'9') ch=getchar();  
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return re;
}
inline void write(int re){
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
bool input(){
	C = read(), G = read();
	for (int i = 1; i <= C; i ++) {
		scanf("%d",&len[i]);
	}
	for (int i = 1; i <= G; i ++) {
		scanf("%d",&w[i]);
	}
}
void print(int x) {
	for(int i = 1; i <= 9999; i ++)
		if(dp[x][i] != -1)
		printf("%d i = %d ", dp[x][i], i);
	printf("\n");
}
bool solve(){
	for(int i = 1; i <= G; i ++) {
		for (int v = 1; v <= p; v ++) {
			for(int k = 1; k <= C; k ++) {
				if(len[k] < 0) dp[i][v][0] = max(dp[i - 1][v], dp[i - 1][v + w[i] * len[k]] + 1);
				else dp[i][v][1] = max(dp[i - 1][v], dp[i - 1][v - w[i] * len[k]] + 1);
			}
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
	input();
	solve();
	return 0;
} 
