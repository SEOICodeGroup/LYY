#include <cstdio>
using namespace std;
//Product by MiracleEEEE 
#define prime 100003
int N, T, head[1000010], num[1000010], inq[1000010], tot;
struct edge{int v, next;}edges[4000010];
struct queue {
	int front, rear, s[1000010];
	void push(int x) {
		s[(rear + 1) % 1000001] = x;
		rear = (rear + 1) % 1000001;
	}
	void pop() {
		front = (front + 1) % 1000001;
	}
	int top() {
		return s[front];
	}
	bool empty() {
		return front == rear;
	}
}q;
inline int read(){
	char ch = getchar(); int re = 0; while (ch<'0' || ch>'9') ch=getchar();  
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return re;
}
inline void write(int re){
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
void ins(int x, int y) {
	edges[++tot].v = y, edges[tot].next = head[x], head[x] = tot;
}
bool input(){
	N = read();
	T = read();
	int temp1, temp2;
	for (int i = 1; i <= T; i ++) {
		temp1 = read(), temp2 = read();
		ins(temp1,temp2);
		ins(temp2,temp1);
	}
	q.push(1); inq[1] = 1;
	while (!q.empty()) {
		int x = q.top(), q.pop();
		inq[x] = 0;
		for (int i = head[x]; i; i = edges[i].next) {
			if (dist[i] > dist[x] + 1) {
				dist[i] = dist[x] = 1;
				if(!inq[i]) q.push(i), inq[i] = 1;
			}
		}
	}
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
