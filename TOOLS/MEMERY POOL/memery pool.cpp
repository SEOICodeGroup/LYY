#include <iostream>
#include <queue>

using namespace std;



struct Node
{
	bool have_value;
	int v;
	Node *left, *right;
	Node() : have_value(false) , left(NULL) , right (NULL){} ;
}; Node* root;


const int maxn = 100;


queue<Node*> freenodes;
Node node[maxn];

Node* newnode()
{
	Node *u = freenodes.front();
	u->left = u->right = NULL;
	u -> have_value = false ;
	freenodes.pop();
	return u;
}


void deletenode (Node* u)
{
	freenodes.push(u);
}


void init()
{
	for(int i = 0; i < maxn ; i ++)
		freenodes.push(&node[i]);
}
int main()
{
	
	return 0;
} 
