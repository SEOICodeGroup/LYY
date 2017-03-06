#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio> 
using namespace std;
//Product by MiracleEEEE 
int k[100000],n,det[6];
const int Prime = 9967;
struct snow{int det[6]; snow* next;snow():det(),next(NULL){}};
struct head{snow *next;head():next(NULL){}}heads[10000];

snow C(int *det){
	int k = det[0],m = 0;
	for(int i= 0; i<= 5; i++){
		if(k > det[i]) {
			k = det[i];m = i;
		}
	}
	snow *l = new snow;
	int pos = 0;
	for(int i = m  ; pos != 6; i == 5?i = 0:i++){
		l->det[pos++] = det[i];
		//cout << " " << l->det[pos - 1];
	}
	
	return *l;
}

int com(int *a, int *b){
	int temp1 = 1,temp2 = 1;

	if (a[0]!=b[0]) return 0;
	else{
		for(int i = 1; i <= 5; i++){
			if(a[i]!=b[i])temp1 = 0;
		}
		for(int i = 1; i <= 5; i++){
			if(a[i]!=b[5-i+1])temp2 = 0;
		}
	}
	return temp1||temp2;
	
	//1 2 3 4 5 6
	//1 6 5 4 3 2 
}
bool Ins(int p, snow k){
	int l = 0;
	snow *crt = heads[p].next;
	while(crt != NULL) {l = com(k.det,crt->det);	crt = crt->next;}
	if(l == 1) return false;
	snow *ncrt= new snow;
	ncrt->next = heads[p].next ;
	heads[p].next = ncrt;
	for(int i= 0 ; i <= 5 ; i++){
		ncrt->det[i] = k.det[i];
	}
	return true;
	
	
}

bool Hash(snow k){
	int sum = 0;
	for(int i = 0; i <= 5; i++){
		sum += k.det[i];
	}
	int hash = sum ;
	hash = (hash << 17) ^ (hash >> 3);
	hash = (hash << 1) | (hash >> 1);
	hash = abs(hash)%Prime;
	if(!Ins(hash,k)) {cout <<"Twin snowflakes found."<<endl; return false;}
	return true;

}

void solve(){
	for(int i = 1; i <= n ; i++){
		int det[6];
		scanf("%d%d%d%d%d%d",&det[0],&det[1],&det[2],&det[3],&det[4],&det[5]);
		snow *k = new snow;
		*k = C(det);
		if(!Hash(*k))return;
	}
	cout <<"No two snowflakes are alike."<<endl;
}
int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif

	cin >> n;
	solve();
	return 0;
} 
