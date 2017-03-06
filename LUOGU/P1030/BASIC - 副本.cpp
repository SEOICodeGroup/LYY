#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef struct BTree
{
	char data;
	BTree *lchild,*rchild; 
}*DBTree,BTree;

int book[9];
char InOrder[9], PostOrder[9], PreOrder[9];
void Build(int PosBegin, int PosEnd ,int InBegin , int InEnd,DBTree &A)
{
	if(book[PosEnd]==0)
	{
		book[PosEnd] = 1;
		A->data = PostOrder[PosEnd];
	}
    if(PosBegin >= PosEnd || InBegin >= InEnd) 
	{
		A->lchild = A->rchild = NULL;
		return ;
		
	}
	int k = 0;
    while(InOrder[k]!=PostOrder[PosEnd]) k++;//gen in INorder
    DBTree L = new BTree; L->data = '0'; 
    Build(PosBegin ,PosBegin + k - InBegin - 1,InBegin,k - 1,L);
    if(L->data!='0')A->lchild = L;
    	else A->lchild = NULL;
    DBTree M = new BTree; M->data = '0';
    Build(PosBegin + k - InBegin ,PosBegin + k - InBegin + InEnd - k -1, k + 1 , InEnd,M);
    if(M->data!='0')A->rchild = M;
    	else A->rchild = NULL;
}

void Pre(DBTree &A)
{
	cout << A->data;
	if(A->lchild)Pre(A->lchild);
	if(A->rchild)Pre(A->rchild);
}


int main()
{

    cin >> InOrder >> PostOrder;
    memset(book,0,sizeof(book));
    DBTree A;
    Build(0,strlen(InOrder)-1,0,strlen(PostOrder)-1,A);
    Pre(A);
    return 0;
}
