#include <iostream>
#include <iomanip> 
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX= 20;
char box[MAX][MAX];
int find1[MAX][MAX];


void FloodFill(int x, int y)
{
	bool book = 1;
	for(int i = 0 ; i < MAX ; i++)
	{
		book = 1;
		for(int j = 0; j < MAX ;j++)
		{
			if(find1[i][j]==1) book = 0;
			else if(!book) box[i][j] = ' ';
		}
	}
}



int bx,by,fr;
void FindX(int x,int y)
{
	fr = 1;
	for(int i = -1 ; i< 2; i++)
		for(int j = -1; j < 2; j++)
		{
			if(i!=j&&box[i][j]=='X'&&find1[i][j]!=1)
			{
				if(x+i==bx&&j+y==by) 
				{
					find1[x+i][y+j] = 1;
					FloodFill(bx,by);
				}
				find1[x+i][y+j] = 1;
				FindX(x+i,y+j);
			}
		}
		return ;
}

void FindY(int x,int y)
{
	
	fr = 1;
	for(int i = -1 ; i< 2; i++)
		for(int j = -1; j < 2; j++)
		{
			if(i!=j&&box[i][j]=='Y'&&find1[i][j]!=1)
			{
				if(x+i==bx&&j+y==by) 
				{
					find1[x+i][y+j] = 1;
					FloodFill(bx,by);
				}
				find1[i][j] = 1;
				FindX(x+i,y+j);
			}
		}
		return ;
}




int main()
{
	memset(box,' ',sizeof(box));
	memset(find1,0,sizeof(find1)); 
	cout << setw(5)<<' ';
	for (int i =0;i<MAX;i++)
		cout << setw(5) << i ;
	cout << endl<<endl;
	
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0 ; j < MAX ; j++)
		box[i][j]=' ';
	}
	for (int i = 0; i< MAX;i++)
	{
		cout << setw(5)<< i ;
		for ( int j =0; j<MAX;j++)
		cout << setw(5)<< box[i][j];
		cout << endl<<endl;
		
	} 
	int player_1x=0;
	int player_1y=0;
	int player_2x=0;
	int player_2y=0;
	while(1)
	{
		cin >> player_1x >> player_1y ;
		box[player_1x][player_1y] = 'O';
		fr = 0;
		bx = player_1x;
		by = player_1y;
		memset(find1,0,sizeof(find1)); 
		FindX(player_1x,player_1y);
		
		system("cls");
		cout << setw(5)<<' ';
		for (int i =0;i<MAX;i++)
			cout << setw(5) << i ;
		cout << endl<<endl;
		
		
		for (int i = 0; i< MAX;i++)
		{
			cout << setw(5)<< i ;
			for ( int j =0; j<MAX;j++)
			cout << setw(5)<< box[i][j];
			cout << endl<<endl;
			
		} 
		cin >> player_2x>>player_2y;
		box[player_2x][player_2y]='Y';
		FindY(player_2x,player_2y);
		memset(find1,0,sizeof(find1)); 
		fr = 0;
		bx = player_2x;
		by = player_2y;system("cls"); 
		cout << setw(5)<<' ';
		for (int i =0;i<MAX;i++)
			cout << setw(5) << i ;
		cout << endl<<endl;
		
	
		for (int i = 0; i< MAX;i++)
		{
			cout << setw(5)<< i ;
			for ( int j =0; j<MAX;j++)
			cout << setw(5)<< box[i][j];
			cout << endl<<endl;
			
		}
		
	}

	
	return 0;
} 

