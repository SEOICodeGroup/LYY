#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio> 
#include <queue>
using namespace std;

typedef struct Lnode
{
	int data;
	Lnode *prior, *next;
}Lnode, *DuLinkList;


void CreatLink(DuLinkList &A)
{
	A->data = 0;
	A->next = A->prior = A;
}

void Insert(int i, DuLinkList A)
{
	DuLinkList ins = new Lnode;
	DuLinkList p = new Lnode;
	p = A;
	p = p->next;
	while(p->data > i)  p = p->next;
	ins->data = i;
	ins->next = p ->next;
	ins->prior = p;
	p->next->prior = ins;
	p->next = ins;
} 

void GetElem(int &p,DuLinkList A, int pos)
{
	DuLinkList q = A;
	for(int i = 1; i <= pos ;i ++) q = q->next;
	p = q->data;
	return;
	
}

int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	DuLinkList LinkA = new Lnode, LinkB = new Lnode;
	CreatLink(LinkA);
	CreatLink(LinkB);
	
	for(int i = 1; i <= 5 ;i ++)
	{
		int x;
		cin >> x;
		Insert(x,LinkA);
	}
	for(int i = 1; i <= 5 ;i ++)
	{
		int x;
		cin >> x;
		Insert(x,LinkB);
	}
	
	for(int i = 1; i <= 5; i++)
	{
		int x;
		GetElem(x,LinkB,i);
		Insert(x,LinkA);
	}
	
	
	DuLinkList p = LinkA;
	for(int i = 0; i< 10;i++)
	{
		p = p->next;
		cout << p->data;
	}
	
	return 0;
} 
