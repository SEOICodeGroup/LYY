#include <iostream>
#include <iomanip> 
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX= 20;
char box[MAX][MAX];
string box1[MAX][MAX];
int used[MAX][MAX];
int count=1;
bool k=true;
int win_deep(char a,int x,int y)
{
	
	
	if(box[x][y]==a&&used[x][y]==0&&k){count++;used[x][y]=1;win_deep(a,x+1,y);}
	else k = false;
	if(box[x][y]==a){if(used[x][y]==0)count++;used[x][y]=1;win_deep(a,x-1,y);}
	else return 0;
	if(count == 6)  return 1;//return 1;
	return 0; 
	
}
int win_weigh(char a,int x,int y)
{//-1
	if(box[x][y]==a&&used[x][y]==0&&k){count++;used[x][y]=1;win_weigh(a,x,y-1);}
	else k = false;
	if(box[x][y]==a){if(used[x][y]==0)count++;used[x][y]=1;win_weigh(a,x,y+1);}
	else return 0;
	if(count == 6)  return 1;//return 1;
	return 0; 
}
	
int win_xie1(char a,int x, int y)
{//- -
	if(box[x][y]==a&&used[x][y]==0&&k){count++;used[x][y]=1;win_xie1(a,x-1,y-1);}
	else k = false;
	if(box[x][y]==a){if(used[x][y]==0)count++;used[x][y]=1;win_xie1(a,x+1,y+1);}
	else return 0;
	if(count == 6)  return 1;//return 1;
	return 0; 
}

int win_xie2(char a, int x,int y)
{//-+
	if(box[x][y]==a&&used[x][y]==0&&k){count++;used[x][y]=1;win_xie2(a,x-1,y+1);}
	else k = false;
	if(box[x][y]==a){if(used[x][y]==0)count++;used[x][y]=1;win_xie2(a,x+1,y-1);}
	else return 0;
	if(count == 6)  return 1;//return 1;
	return 0; 
}


int main()
{
	memset(box,' ',sizeof(box));
	memset(used,0,sizeof(used)); 
	cout << setw(5)<<' ';
	for (int i =0;i<MAX;i++)
		cout << setw(5) << i ;
	cout << endl<<endl;
	
	for(int i = 0; i < MAX; i++)
	{
		for(int j = 0 ; j < MAX ; j++)
		box1[i][j]="__|";
	}
	for (int i = 0; i< MAX;i++)
	{
		cout << setw(5)<< i ;
		for ( int j =0; j<MAX;j++)
		cout << setw(5)<< box1[i][j];
		cout << endl<<endl;
		
	} 
	int player_1x=0;
	int player_1y=0;
	int player_2x=0;
	int player_2y=0;
	player1: 
	while (cout << "last oppsite at "<< player_2x << ' '<< player_2y&&scanf("%d %d",&player_1x,&player_1y)==2&&cout<<endl)
	{
		
		if(box[player_1x][player_1y]=='O'||box[player_1x][player_1y]=='X')
			{
				cout << "please input again !!!";
				goto player1;
			}
		
		if(player_1x==-1) 
		{
			cout << endl;
			
			box[player_2x][player_2y]=' ';
			box1[player_2x][player_2y]="__|";
			cout << setw(5) << ' ';
			for(int i = 0 ; i < MAX; i++)
			cout << setw(5) << i;
			cout << endl<<endl;
			for (int i = 0; i< MAX;i++)
			{
				cout << setw(5)<< i ;
			for ( int j =0; j<MAX;j++)
				cout << setw(5)<< box1[i][j];
				cout << endl<<endl;
		
	
		
			} 
			goto player2;
		}
		system("cls");
		box[player_1x][player_1y]='O';
		box1[player_1x][player_1y]="O";
		cout << setw(5)<<' ';
	for (int i =0;i<MAX;i++)
		cout << setw(5) << i ;
	cout << endl<<endl;
	for (int i = 0; i< MAX;i++)
	{
		cout << setw(5)<< i ;
		for ( int j =0; j<MAX;j++)
		cout << setw(5)<< box1[i][j];
		cout << endl<<endl;
		
	
		
	}   memset(used,0,sizeof(used));
		count=1;k=true;memset(used,0,sizeof(used)); 
		if(win_deep('O',player_1x,player_1y)) {cout << "Player 1 Win!!!";	break;}
		count=1;k=true;memset(used,0,sizeof(used)); 
		if(win_weigh('O',player_1x,player_1y)) {cout << "Player 1 Win!!!";	break;}
		count=1;k=true;memset(used,0,sizeof(used)); 
		if(win_xie1('O',player_1x,player_1y)) {cout << "Player 1 Win!!!";	break;}
		count=1;k=true;memset(used,0,sizeof(used)); 
		if(win_xie2('O',player_1x,player_1y)) {cout << "Player 1 Win!!!";	break;}
		player2:
		cout << "last oppsite at "<< player_1x << ' '<< player_1y;
		scanf("%d%d",&player_2x,&player_2y);
		cout <<endl;
		
		if(box[player_2x][player_2y]=='O'||box[player_2x][player_2y]=='X')
			{
				cout << "please input again !!!";
				goto player2;
			}
		if(player_2x==-1) 
		{
			box[player_1x][player_1y]=' ';
			box1[player_1x][player_1y]="__|";
			cout << endl;
			cout << setw(5) << ' ';
			for(int i = 0 ; i < MAX; i++)
			cout << setw(5) << i;
			cout << endl<<endl;
			for (int i = 0; i< MAX;i++)
			{
			
				cout << setw(5)<< i ;
				for ( int j =0; j<MAX;j++)
				cout << setw(5)<< box1[i][j];
				cout << endl<<endl;
		
	
		
			} 
			goto player1;
			
		}
		system("cls");
		box[player_2x][player_2y]='X';
		box1[player_2x][player_2y]="X";
		
		
	cout << setw(5)<<' ';
	for (int i =0;i<MAX;i++)
		cout << setw(5) << i ;
	cout << endl<<endl;
	for (int i = 0; i< MAX;i++)
	{
		cout << setw(5)<< i ;
		for ( int j =0; j<MAX;j++)
		cout << setw(5)<< box1[i][j];
		cout << endl<<endl;
		
	} 
		memset(used,0,sizeof(used)); 
		count=1;k=true;memset(used,0,sizeof(used)); 
		if(win_deep('X',player_2x,player_2y)) {cout << "Player 2 Win!!!";	break;}
		count=1;k=true;memset(used,0,sizeof(used)); 
		if(win_weigh('X',player_2x,player_2y)) {cout << "Player 2 Win!!!";	break;}
		count=1;k=true;memset(used,0,sizeof(used)); 
		if(win_xie1('X',player_2x,player_2y)) {cout << "Player 2 Win!!!";	break;}
		count=1;k=true;memset(used,0,sizeof(used)); 
		if(win_xie2('X',player_2x,player_2y)) {cout << "Player 2 Win!!!";	break;}
		count=1;k=true;
	}
	

	
	
	
	
	
	
	return 0;
} 

