#include<cstdio>

#include<cstring>

#include<cstdlib>

#include<algorithm>

#include<cmath>

using namespace std;

const int MX=200100;

const double ID_NUM=0.55;

int n,m,k,a[MX],lztg[MX],bel[MX],cntq[251][MX],q,qc;

void recal(int p)

{

    int s=q*(p-1)+1;

    for(int i=s;bel[i]==p;i++)cntq[p][a[i]%k]++;

}

void psdw(int p)

{

    if(lztg[p]==0)return;

    int s=q*(p-1)+1;

    for(int i=s;bel[i]==p;i++)a[i]=(a[i]+lztg[p])%k;

    lztg[p]=0;

}

void rd(int &x)

{

    x=0;char ch=getchar();

    while(ch<'0'||ch>'9')ch=getchar();

    while(ch>='0'&&ch<='9'){x*=10;x+=ch-'0';ch=getchar();}

}

int main()

{

    rd(n);rd(m);rd(k);

    q=(int)pow((double)n,ID_NUM);

    for(int i=1;i<=n;i++){rd(a[i]);a[i]%=k;}

    for(int i=1;i<=n;i++)bel[i]=(i-1)/q+1;

    qc=bel[n];

    for(int i=1;i<=qc;i++)recal(i);

    for(int p=1;p<=m;p++)

    {

        char op[10];scanf("%s",op);

        if(op[0]=='a')

        {

            int l,r,c;rd(l);rd(r);rd(c);

            if(bel[l]==bel[r])

            {

                for(int i=l;i<=r;i++){cntq[bel[i]][(a[i]+c)%k]++;cntq[bel[i]][a[i]]--;a[i]=(a[i]+c)%k;}

            }

            else

            {

                for(int i=l;bel[i]==bel[l];i++){cntq[bel[i]][(a[i]+c)%k]++;cntq[bel[i]][a[i]]--;a[i]=(a[i]+c)%k;}

                for(int i=r;bel[i]==bel[r];i--){cntq[bel[i]][(a[i]+c)%k]++;cntq[bel[i]][a[i]]--;a[i]=(a[i]+c)%k;}

                for(int i=bel[l]+1;i<bel[r];i++)lztg[i]=(lztg[i]+c)%k;

            }

        }

        else

        {

            int l,r;rd(l);rd(r);

            int ans=0;

            if(bel[l]==bel[r])

            {

                for(int i=l;i<=r;i++)if((a[i]+lztg[bel[i]])%k==0)ans++;

            }

            else

            {

                for(int i=l;bel[i]==bel[l];i++)if((a[i]+lztg[bel[i]])%k==0)ans++;

                for(int i=r;bel[i]==bel[r];i--)if((a[i]+lztg[bel[i]])%k==0)ans++;

                for(int i=bel[l]+1;i<bel[r];i++)ans+=cntq[i][(k-lztg[i])%k];

            }

            printf("%d\n",ans);

        }

    }

    return 0;

}