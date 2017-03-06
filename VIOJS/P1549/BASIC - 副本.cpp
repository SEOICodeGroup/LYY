#include <iostream>
#include <algorithm>
using namespace std;
int N,b;
int num[100000];
int main()
{
	cin >> N,b;
	int book;
	for(int i = 0; i < N ; i++) 
	{
		cin >> num[i];
		if(num[i]==b) book = i;	
	}
	
	for(int i = 1; i < N ; i++)
	{
		if(book-i >= 0) 
	}
	
	return 0;
 } 
