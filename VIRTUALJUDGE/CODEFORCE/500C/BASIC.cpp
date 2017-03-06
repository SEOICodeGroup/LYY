#include <cstdio>
using namespace std;
//Product by MiracleEEEE
int numBooks , numDays , k = 1;
int weight[510] , order[1010] , vis[510] ; 
struct Node{int id ; int next;} Books[1510];
inline int read(){
	char ch = getchar(); int re = 0; bool fl  = 1; if(ch == '-') {fl = 0 ; ch = getchar();}
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return fl ? re : -re;
}
inline void write(int re){
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
void Ins ( int i ) {
	Books[k].next = Books[0].next;
	Books[0].next = k ;
	Books[k++].id = i ; 
}

bool input(){	
	Books[0].next = 1;
	numBooks = read() ; numDays = read() ;
	for( int i = 1 ; i <= numBooks ; i ++ ) {
		weight[i] = read() ;
	}
	int tail = 1 ;
	for( int j = 1 ; j <= numDays ; j ++ ) {
		order[j] = read() ;
		if( vis [ order[j]] == 0){Books[tail].id = order[j] ; Books[tail++].next = ++k;}
		vis[order[j]] = 1;
	} Books[tail - 1].next = 0;
	return true;
}

int Del ( int i ) {
	if( Books[Books[0].next].id == i) return 0 ;
	int ite = Books[0].next , res = weight[Books[Books[0].next].id];
	while(Books[Books[ite].next].id != i) res += weight[Books[Books[ite].next].id] , ite = Books[ite].next ;
	Books[ite].next = Books[Books[ite].next].next ;
	Ins( i ) ;
	return res ;
}
bool solve(){
	long long ans = 0 ;
	for( int i = 1 ; i <= numDays ; i ++ ) {
		ans += Del( order[i] );
	}
	printf("%lld",ans) ;
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
