#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int x,now=-9999999,ans=-9999999,i,n;   //now��ʾ����ǰλ�õ�����Ӷκ�
int max(int a,int b)
{
    return(a>b? a:b);
}
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&x);
        now=max(x,now+x);   //����Ȼֻ�е�ǰ��ĺʹ���0ʱ �Űѵ�ǰx����ǰ��
        ans=max(now,ans);   //����ans
    }
    printf("%d",ans);
    return 0;
}
