#include <cstdio>
#include <cstring> 
using namespace std;
char A[200005],B[200005]; 
//Product by MiracleEEEE 
inline int read_num() { 
	char ch = getchar(); int re = 0; bool fl  = 1; if(ch == '-') {fl = 0 ; ch = getchar();}
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return fl ? re : -re;
}
inline void write(int re) {
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
bool input(){
	scanf("%s",A) ;
	scanf("%s",B) ;
	return true;
}

bool check ( int begin, int end , int left , int right  ) {
	for(int i = 0 ; i <= end - begin ; i ++) {
		if( A[begin + i] != B[left + i]) return false;
	}
	return true;
}

bool dfs( int begin, int end , int left ,int right ) {
	if( ( end - begin ) % 2 == 0 ) return check ( begin , end , left , right );
	else {
		int mid1 = ( begin + end ) >> 1 , mid2 = ( left + right ) >> 1;
		if(check (begin , mid1 , left , mid2 ) && check(mid1 + 1, end, mid2 + 1, right )) return true;
		if(check (begin ,mid1, mid2+ 1, right) && check(mid1 + 1, end, left, mid2)) return true;
		else return ( dfs (begin , mid1 , left , mid2 ) && dfs(mid1 + 1, end, mid2 + 1, right )) || dfs (begin ,mid1, mid2+ 1, right) && dfs(mid1 + 1, end, left, mid2);
	}
}

bool solve(){
	return dfs( 0 , strlen (A) - 1 , 0 , strlen (A) - 1 );
}
int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	input();
	if ( solve() ) printf("YES");
	else printf("NO");
	return 0;
} 
