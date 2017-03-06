#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
char a[105],b[105];
int main(){
	while(~scanf("%s",a)){
		scanf("%s",b);
		int A=strlen(a);
		int B=strlen(b);
		
		
		int i=0,j=0;
		for(i=0;i<A;++i){
			for(j=i;j<B+i&&j<A;++j){
				if(((a[j]-'0')+(b[j-i]-'0'))>3)break;
			}
			if(j>=B+i||j>=A)break;
		}
		int k1,k2;
		if(i<A)	k1=A+B-j+i;
		else k1=A+B;
		
			
		
		for(i=0;i<B;++i){
			for(j=i;j<A+i&&j<B;++j){
				if(((b[j]-'0')+(a[j-i]-'0'))>3)break;
			}
			if(j>=A+i||j>=B)break;
		}
		
		if(i<B)	k2=A+B-j+i;
		else k2=A+B;	
		int ans;
		ans=k1<k2?k1 :k2;	
		cout<<ans<<endl;
		
	}
	
	
	return 0;
}





