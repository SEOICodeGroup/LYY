#include <cstdio>
#include <iostream>
using namespace std;
//Product by MiracleEEEE
const int MAX = 5000 + 5 ;
int n , ans ;
int s[MAX] = { 0 }; 
inline int read_num(){
	char ch = getchar(); int re = 0; bool fl  = 1; if(ch == '-') {fl = 0 ; ch = getchar();}
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return fl ? re : -re;
} 
inline void write(int re){
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
bool input(){
	scanf("%d",&n);	
	for ( int i = 1 ; i <= n ; i ++ ) {
		scanf ("%d" ,&s[i] );
	}
	return true;
}

int Geth ( int l , int r ) {
	return r - l + 1 ; 
}
int Getw ( int l , int r ) {
	int res = s[l] ;
	for(int i = l ; i != r + 1 ; i ++ ) {
		res = min ( res , s[i] ) ;
	}
	return res ;	
}

int  dfs( int l , int r ) {
	if ( l > r ) return 0 ;
	int num = 0;
	int h = Geth ( l , r ) ;
	int w = Getw ( l , r ) ; 
	if( h <= w) {
		return h ;
	} else {
		num += w ;
		int book = l ; 
		for( int i = l ; i != r + 1 ; i ++ ) {
			s[i] -= w;
			if ( s[i] == 0 )	num += dfs ( book , i - 1 ) , book =  i + 1; 
		}
		num += dfs ( book  , r ) ; 
	}
	return min ( num , h );
}
bool solve(){
	ans = dfs( 1 , n );
	printf("%d",ans);
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
