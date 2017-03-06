
#include <cstdio> 
#include <string.h>
int limit = 3;
char str_1[100],str_2[100];
int box[100];
int began = 0;


int main()
{
	#ifdef LOCAL
	freopen("TEXT.txt","r",stdin);
	freopen("OUTPUT.txt","w",stdout);
	#endif
	memset(str_1,'0',sizeof(str_1));
	memset(str_2,'0',sizeof(str_2));
	while(~scanf("%s",str_1))
	{
		scanf("%s",str_2);
		int len_1=strlen(str_1);
		int len_2=strlen(str_2);
		int ans;
		if(len_1>=len_2)ans=len_1;
		else ans=len_2;
		bool ok=false;
		int count = 0;
		for(began=0;ok==false;began++)
		{
			count = 0;
			if(len_1>=len_2)
			{
			for(int i = 0;i<len_1;i++)
			{
				if(i+began<=len_1-1&&str_2[i]-'0'+str_1[i+began]-'0'>3) {count ++;if(len_2+began>=len_1)ans++;break;}
				else if(count!=len_2-1&&i+began>len_2) count++;
				else if(count!=len_2-1) {count++;continue;
				}
				
				if(count == len_2-1){ok = true;
				break;}
				
				
			
			}
			}
			if(len_1<len_2)
			{
			for(int i = 0;i<len_2;i++)
			{
				if(i+began<=len_2-1&&str_1[i]-'0'+str_2[i+began]-'0'>3) {count ++;if(len_1+began>=len_2)ans++;break;}
				else if(count!=len_2-1&&i+began>len_1)count++;
				else if(count!=len_1-1) {count++;continue;
				}
				
				else if(count == len_1){ok=true;break;}
			}
			}
			
	
		
		}
	 	memset(str_1,'0',sizeof(str_1));
		memset(str_2,'0',sizeof(str_2));
	printf("%d\n",ans);
	
	
}
	return 0;
} 
