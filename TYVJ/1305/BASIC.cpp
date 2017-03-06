#include <cstdio>
using namespace std;
//Product by MiracleEEEE 
int n, m,q[300010];
long long s[300010]; 
long long ans;
struct p{int pos, key;};

struct queue{int front, rear; p k[300010];
	void print() {
		int i = front ;
		printf("front = %d rear = %d : ",front,rear);
		for(i; i < rear; i ++) {
			printf("%d ",k[i].key);
		}
		putchar('\n');
	}	
	void pop () {
		if (rear > front && rear != 0) rear--;
	}
	int top () {
		return k[rear - 1].key;
	}
	void push ( int pos, int key ) {
		while ( rear > front && top() > key ) pop();
		k[rear].key = key;
		k[rear++].pos = pos;
		//print();
	}

}l;
inline int read(){
	char ch = getchar(); int re = 0; bool fl  = 1; if(ch == '-') {fl = 0 ; ch = getchar();} 
	while (ch<'0' || ch>'9') ch=getchar();  
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return fl ? re : -re;
}
inline void write(int re){
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
bool input(){
	n = read(), m = read();
	for ( int i = 1; i <= n; i ++ ) {
		q[i] = read();
		s[i] = s[i-1] + q[i];
	}
	return true;
}
bool solve(){
    ans = q[1];
	for ( int i = 1; i <= n ; i ++ ) {
		if( i <= m ) ans = ans > s[i] ? ans : s[i] ;
		while( l.k[l.front].pos < i - m  && l.front < l.rear ) l.front++;
		ans = ans > s[i] - l.k[l.front].key ? ans : s[i] - l.k[l.front].key;
		l.push( i, s[i] );
	}
	//if(l.front != n ) ans = ans > s[n] - l.k[l.front].key ? ans : s[n] - l.k[l.front].key;
	printf("%lld",ans);
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
