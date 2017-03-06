#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio> 
using namespace std;

int cnt = 1 ; 
int _country , _roat ;
struct roat_
{
    int x;
    int to;
    int time;
}roat[100005];
int pre[100005];

int find(int x)
{
    int r = x;
    while(pre[r]!= r) r = pre[r];
    int i = x , j;
    while(i != r)
    {
        j = pre[i];
        pre[i] = r;
        i = j;
    }
    return r;
    
    
}

void join(int u)
{
    int fx = find(roat[u].x);
    int fy = find(roat[u].to);
    if(fy!=fx) 
    {
    	cnt ++ ;
        pre[fx] = fy;
    };
}


int _cmp(roat_ a ,roat_ b)
{
    return a.time < b.time;
}

int main()
{
    #ifdef LOCAL
    //freopen("TEXT.txt","r",stdin);
    //freopen("OUTPUT.txt","w",stdout);
    #endif
     
    cin >> _country >> _roat ; 
    
    int x , y , t ;
    for(int i = 1 ; i <= _roat ; i++) cin >> roat[i].x >> roat[i].to >> roat[i].time ; 
    sort(roat + 1, roat + _roat + 1, _cmp);
    
    for(int i = 1; i <= _roat ; i++) pre[i] = i;
    
    
    for(int i = 1 ; i <= _roat ; i++)
    {
        join (i);
        if(cnt == _country) 
        {
        	cout << roat[i].time;
        	return 0;
        	
		}
        
    }
     
    

    cout << -1;
    return 0;
} 
