#include <algorithm>
#include <string.h>
#include <cstdio> 
#include <set>
using namespace std;
int _comp(int a,int b)
{
	if (a>b) return 1;
	else return 0;
}
typedef long long LL;
set<LL> s;
LL que[1000005];
int count1= 1;
int main()
{
	#ifdef LOCAL
	//freopen("TEXT.txt","r",stdin);
    //freopen("OUTPUT.txt","w",stdout);
	#endif
	
	int basic;
	int num;
	while(scanf("%d%d",&basic,&num)!=EOF) 
	{
		 if(que[0]==0){que[count1]=basic;s.insert(basic);}
		 

		 for(int i = 1 ;;i++)
		 {
		 		if(count1 ==num) break;
				LL x = que[count1];
				count1--;
				if(!s.count(x)){que[count1]=x;s.insert(x);count1 ++;
				}	
				if(!s.count(2*x+1) ){que[count1]=2*x+1;s.insert(2*x+1);count1 ++;
				}			
				if(!s.count(3*x+1)){que[count1]=3*x+1;s.insert(3*x+1);count1 ++;
				}
		 	sort(que,que+count1,_comp);
		 }
		
		printf("%d\n",que[count1]);	 
	 	 
  	 memset(que,0,sizeof(que));
	 s.clear();

		 
		 
	} 
	 
	
	
	
	
	return 0;
} 
