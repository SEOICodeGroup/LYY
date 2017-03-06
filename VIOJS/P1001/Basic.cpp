#include<iostream>
using namespace std;
int main()
{
    string a,g;
    int b,c,f,n,money=0,result=0,sum=0;
    char d,e;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c>>d>>e>>f;
        money=0;
        if(b>80&&f>=1)
        money+=8000;
        if(b>85&&c>80)
        money+=4000;
        if(b>90)
        money+=2000;
        if(b>85&&e=='Y')
        money+=1000;
        if(c>80&&d=='Y')
        money+=850;
        sum+=money;
        if(result<money)
        {
            result=money;
            g=a;
        }
    }
    cout<<g<<endl<<result<<endl<<sum<<endl;
    return 0;
}
