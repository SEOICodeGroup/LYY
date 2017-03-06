#include<string.h>
#include<stdio.h>
long long q[1000005],a,head1,head2,tail,n;
int set0()
{
	head1=1;q[1]=a;head2=1;tail=1;
}
int suan()
{
	int i,j;
	set0();
	while(tail<n)
	{
	int x=q[head1]*2+1,y=q[head2]*3+1;
	if(x>y)
	{
		q[++tail]=y;
		head2++;
	}
	else
	if(x<y)
	{
	q[++tail]=x;
	head1++;
	}
	else
	{
	q[++tail]=x;
	head1++;
	head2++;
	}
// printf("*");
	}	
	printf("%d\n",q[n]);

	}

int main()
{


while(scanf("%d %d",&a,&n)!=EOF)
suan();
return 0;
}
