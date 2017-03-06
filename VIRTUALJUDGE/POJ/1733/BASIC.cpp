#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
//Product by MiracleEEEE 
inline int read(){
	char ch = getchar(); int re = 0; while (ch<'0' || ch>'9') ch=getchar();  
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return re;
}
inline void write(int re){
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
struct dat{int l, r; char oe[5];}data[5005];
int set[10010],s[10010],n,q,cnt,r[10010]; 
bool input(){
	n = read(); q = read();
	for ( int i = 1; i <= q; i ++ ) {
		data[i].l = read(), data[i].r = read();
		scanf("%s", data[i].oe); data[i].l--;
		s[++cnt] = data[i].l, s[++cnt] = data[i].r;
	}
	sort ( s + 1, s + cnt + 1 );
	cnt = unique( s + 1, s + cnt + 1 ) - s;
	for ( int i = 1; i <= cnt ; i ++) set[i] = i,r[i] = 0;
	return true;
}
int Bs ( int key ) {
	int l = 1, r = cnt;
	while ( l <= r) {
		int mid = ( l + r ) >> 1;
		if ( s[mid] == key ) return mid;
		if ( s[mid] < key ) l = mid + 1;
		else r = mid - 1;
	}
	return -1;
}

int find ( int key ) {
	if ( key != set[key] ) {
		int f = set[key];  printf("f = %d r[f] = %d r[key] = %d\n", f,r[f],r[key]);
		set[key] = find(set[key]);
		r[key] ^= r[f]; printf(" after find -> f = %d key  = %d r[f] = %d r[key] = %d\n",f,key,r[f],r[key]); 			// 1 - 2 odd 2 - 3 even 3 - 4 odd 1 - 4 odd ��������������ݣ� �ڶ���ǰ������ʱ���Ѿ�ȷ��1 - 4 �� even��
	} return set[key];
}

bool solve(){
	int ans = 0;
	for ( int i = 0; i < cnt; i ++ ) printf("%d\n", s[i]);
	for ( int i = 1; i <= q; i ++ ) {
		int u = Bs(data[i].l), v = Bs(data[i].r); //���ֲ��� u v ���±�
		int fu = find(u), fv = find(v);			  // �ҵ�u v ���ڵļ���
		if ( fu == fv ) {
			if ( r[u] == r[v] && data[i].oe[0] == 'o' ) break; // 1-u �� 1-v�������ż��һ�� Ҳ����˵u-v��Ӧ����ż����1
			if ( r[u] != r[v] && data[i].oe[0] == 'e' ) break; // ��ż�Բ�һ�£�Ӧ����������1
		} else {
			set[fu] = fv;						  // �������ļ��ϣ� ʹ�乹��һ������������
			if ( data[i].oe[0] == 'o' ) r[fu] = r[u]^r[v]^1; else r[fu] = r[u]^r[v];// ������ȷ�� u v ����ż�ԣ�����˵���ǵ���ż���෴���ڸ���ֵ��ʱ�������Ƕ�����������ż�����У���Ϊ���ǵ�����ͬ�����෴
			printf("r[fu] = %d fu = %d\n", r[fu],fu);
		}  // 1 - 2 odd 2 - 3 even 3 - 4 odd 1 - 4 odd 1 - 8 odd 1 -> fu  = 8 1 - 3 even 1 - 8 even 3 - 8 odd 
		ans ++;
	}
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
