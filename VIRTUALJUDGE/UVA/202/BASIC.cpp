
#include <string.h>
#include <cstdio> 

int ans[1005];
int shang[3005];
int main()
{
	#ifdef LOCAL
	freopen("TEXT.txt","r",stdin);
	//freopen("OUTPUT.txt","w",stdout);
	#endif
	bool is=false;
	int a,b;
	int len = 0;
	int zs;
	while(scanf("%d %d",&a,&b)!=EOF&&b)
	{
		printf("%d/%d=",a,b);
		zs = a/b;
		printf("%d.",zs);
		a = a - zs*b;
		is = false;
	    len = 0;
		memset(shang,0,sizeof(shang));
		shang[a]=1;
		for(int i = 1 ; i <=1000;i++)
		{
			if(a<b){a*=10;}
			while(a<b){ans[i]=0;i++;a*=10;len++;}
			
			ans[i]=a/b;
			a=a%b;
			if(shang[a]!=0) {len++;break;}
			if(a==0) {is=true;len++;break;} 
			else {
			shang[a]=1;len++;}
		
		}
		
		if(is){

			for(int i = 1; i<=len;i++)
			printf("%d",ans[i]);
			printf("(0)\n");len=1;
		}else if(len<=50){
		printf("(");
		for(int i = 1; i<=len;i++)
		printf("%d",ans[i]);
		printf(")\n");}
		else{printf(")");
		for(int i = 1; i<=50;i++)
		printf("%d",ans[i]);
		printf("...)\n");
		}
		
		printf("%d = number of digits in repeating cycle\n", len);
	} 
	
	
	
	
	
	
	return 0;
} 
