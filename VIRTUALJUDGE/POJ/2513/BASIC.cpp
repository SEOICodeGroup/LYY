#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char B[15],E[15],len,num;
int ans,tag;
//Product by MiracleEEEE 
inline int read_num(){
	char ch = getchar(); int re = 0; bool fl  = 1; if(ch == '-') {fl = 0 ; ch = getchar();}
	while( ch >= '0'&& ch <= '9'){re = re * 10 + ch - '0'; ch = getchar();} return fl ? re : -re;
}
inline void write(int re){
	if(re < 0) {putchar('-');re = -re;}
	if(re > 9) write(re / 10); putchar(re % 10 + '0');
}
//===========================================hash========================================================
int Hash[20];int k = 31;
int hash(char *str ,int len) {
	int p = 13131;
	Hash[0] = str[0];
	for(int i = 1; i <=  len ; i++) {
		Hash[i] = (Hash[i - 1] * k + str[i]) % p;
	}
	return Hash[len];
} 
//===========================================并查集======================================================================
int Set[250010];
int find(int v){
	return (Set[v] ==  v)? v : Set[v] = find(Set[v]); 
}

//blue . red
//set[blue]  = blue set[red] = red
//blue green
//set[blue] = 0
//set[green] = green
//green blue
//set[green] = 0
//set[blue] = blue;
//并查集  
//===========================================TIRE==========================================================================
int TireNode[40][40]; int n; vector<int> book[40];
void ins(char *a,int pos,int k){
	if(len == pos){
		if(!book[k].empty() && find(Set[num]) != find(Set[book[k][book[k].size() - 1]])){
			tag = 1;
			Set[num] = Set[book[k][book[k].size() - 1]];
			find(num);
			book[k].pop_back();
			return ;
		}
		book[k].push_back(num);
		return;
	}
	if(TireNode[k][a[pos] - 'a']){
		ins(a, pos + 1, TireNode[k][a[pos] - 'a']);
	}else{
		TireNode[k][a[pos] - 'a'] = n++;
		ins(a, pos + 1, TireNode[k][a[pos] - 'a']);
	}
}
//=========================================================================================================================
bool solve(){
	for(int i = 1; i <= 250000 ; i++) Set[i] = i;
	while(1){
		num++;
		if(scanf("%s %s\n", B, E) != 2) break;
		tag = 0;
		len = strlen(B) - 1;
		ins(B, 0, 0);
		len = strlen(E) - 1;
		ins(E, 0, 0);
	} 
	for(int i = 1; i <= num; i++) if(Set[i] != Set[1])ans= 1;
	if(ans)printf("Imossible");
	else printf("Posible");
	return true;
}
//=========================================================================================================================
int main()
{
	#ifdef LOCAL
	freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	solve();
	return 0;
} 
