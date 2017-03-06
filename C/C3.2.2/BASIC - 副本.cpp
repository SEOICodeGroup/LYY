#include<iostream>



typedef long long ll;
typedef struct Lnode
{
	ll data;
	Lnode *next,*prior;
	
}Lnode , *LinkList;
using namespace std;


LinkList L = new Lnode;



void Cal()
{
	ll sum = 0;
	Lnode *ite = L;
	int k = 0;
	while(!k||(k&&ite!=L)){
		sum += ite->data;
		ite = ite->next;
		k = 1;
	}
	L->data = sum;
	L = L->next;
}


void Ins(int i )
{
	Lnode *k = new Lnode;
	k->next = L;
	k->prior = L->prior;
	L->prior->next = k;
	L->prior = k;
	k->data = i;
	L = k;
	
} 

//K A B C D 
int main()
{
	L->next = L->prior = L;
	L->data = 0;
	
	int K = 0;
	cin >> K;
	
	for(int i = 2; i <= K ; i++)
	{
		Ins(0);
	}
	
	L->data = 1;
	
	int M;
	cin >> M;
	for(int i = 1 ; i <= M ; i++ )
	{
		Lnode *ite = L;
		int k = 0;
		while(!k||(k&&ite!=L)){
		cout << ite->data<<" ";
		ite = ite->next;
		
		k = 1;
	}cout << endl;
		Cal();
	}
	return 0;
} 
