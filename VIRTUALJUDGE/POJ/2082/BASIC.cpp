#include <cstdio>
using namespace std;
//Product by MiracleEEEE 
inline int read_num(){
	char ch = getchar(); int re = 0; bool fl  = 1; if(ch == '-') {fl = 0 ; ch = getchar();}
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return fl ? re : -re;
}
inline void write(int re){
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
bool input(){
	
	return true;
}
bool solve(){
	
	return true;
}
int main()
{
	#ifdef LOCAL
	freopen("TEXT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);
	#endif
	input();
	solve();
	return 0;
} 
