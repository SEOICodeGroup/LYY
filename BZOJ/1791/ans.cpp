#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <stack>  
#include <cctype>  
#include <iostream>  
#define N 1050000  
using namespace std;  
inline int getc() {  
    static const int L = 1<<15;  
    static char buf[L],*S=buf,*T=buf;  
    if(S==T){  
        T=(S=buf)+fread(buf,1,L,stdin);  
        if(S==T)return EOF;  
    }  
    return *S++;  
}  
inline int getint() {  
    int c;  
    while(!isdigit(c = getc()));  
    int tmp = c-'0';  
    while(isdigit(c=getc()))  
        tmp=(tmp<<1)+(tmp<<3)+c-'0';  
    return tmp;  
}  
struct Syndra  
{  
    int u,v,len,next;  
}e[N];  
struct Fiona  
{  
    int edge,flag1,flag2;  
    long long temp,max1,max2;  
}s[N];  
int head[N],cnt,n;  
int visit[N],next[N],len[N];  
int i,j,k;  
long long sa[N],pre[N],ans;  
void add(int u,int v,int len)  
{  
    cnt++;  
    e[cnt].u=u;  
    e[cnt].v=v;  
    e[cnt].len=len;  
    e[cnt].next=head[u];  
    head[u]=cnt;  
}  
int que[N<<1];  
long long sum[N<<1],ret;  
long long dp(int num)  
{  
    int top,tail;  
    int u,b,star;  
    int et;  
    for(et=1;et<(num<<1);et++)  
    {  
        sum[et]=sum[et-1]+pre[(et-1)>=num?(et-1-num):(et-1)];  
    }  
    top=tail=0;  
    /* 
    que[top]=0; 
    for(et=1;et<(num<<1);et++) 
    { 
        while(et-que[top]>=num)top++; 
        u=que[top]; 
        ret=max(ret,sa[et>=num?et-num:et]+sa[u>=num?u-num:u]+sum[et]-sum[u]); 
        b=que[tail]; 
        que[++tail]=et; 
        for(star=tail;star>top;b=que[star-1]) 
        { 
            if(sum[et]-sum[b]+sa[b]<sa[et]) 
            { 
                que[star]=b; 
                que[--star]=et; 
            } 
            else break; 
        } 
        tail=star; 
    } 
    */  
    que[tail++]=0;  
    for(et=1;et<(num<<1);++et)  
    {  
        while(top<tail&&et-que[top]>=num)++top;  
        u=que[top];  
        ret=max(ret,sa[et>=num?et-num:et]+sa[u>=num?u-num:u]+sum[et]-sum[u]);  
        while(top<tail&&sa[et>=num?et-num:et]>=sa[que[tail-1]>=num?que[tail-1]-num:que[tail-1]]+sum[et]-sum[que[tail-1]])--tail;  
        que[tail++]=et;  
    }  
    return ret;  
}  
void build()  
{  
    cnt=1;  
    memset(head,0,sizeof(head));  
    memset(visit,0,sizeof(visit));  
    n=getint();  
    for(i=1;i<=n;i++)  
    {  
        next[i]=getint();  
        len[i]=getint();  
        add(next[i],i,len[i]);  
    }  
}  
stack<int>sk;  
int fa[N];  
void dfs(int x)  
{  
    if(s[x].edge==0)  
    {  
        sk.pop();  
        if(s[x].flag2)ret=max(ret,s[x].max1+s[x].max2);  
        if(visit[x]==-1)  
            return ;  
        x = sk.top();  
        {  
            int v,tt=s[x].edge;  
            v=e[tt].v;  
            visit[v]=i;  
            s[x].temp=s[v].max1+e[tt].len;  
            if(s[x].max1<s[x].temp)  
            {  
                if(s[x].flag1)s[x].max2=s[x].max1,s[x].flag2=1;  
                else s[x].flag1=1;  
                s[x].max1=s[x].temp;  
            }  
            else if(s[x].max2<s[x].temp)s[x].max2=s[x].temp,s[x].flag2=1;  
            s[x].edge=e[tt].next;  
        }  
        return ;  
    }  
    int v,tt=s[x].edge;  
    v=e[tt].v;  
    if(visit[v]==-1)  
    {  
        s[x].edge=e[tt].next;  
        return ;  
    }  
    fa[v]=x;  
    s[v].edge=head[v];  
    sk.push(v);  
}  
long long handle(int x)  
{  
    s[x].edge=head[x];  
    sk.push(x);  
    while(!sk.empty())  
    {  
        dfs(sk.top());  
    }  
    return s[x].max1;  
}/*handle(long long)+dfs(void)=dfs(long long)*/  
/*long long dfs(int x) 
{ 
    int et,v,flag1,flag2; 
    long long max1,max2; 
    for(max1=max2=0,flag1=flag2=0,et=head[x];et;et=e[et].next) 
    { 
        v=e[et].v; 
        if(visit[v]==-1)continue; 
        temp=dfs(v)+e[et].len; 
        visit[v]=i; 
        if(max1<temp) 
        { 
            if(flag1)max2=max1,flag2=1; 
            max1=temp; 
            flag1=1; 
        } 
        else if(max2<temp)max2=temp,flag2=1; 
    } 
    if(flag2)ret=max(ret,max1+max2); 
    return max1; 
}*/  
int main()  
{  
    int u,v;  
    build();  
    for(i=1;i<=n;i++)  
    {  
        if(!visit[i])  
        {  
            for(u=i;!visit[u];u=next[u])  
            {  
                visit[u]=i;  
            }  
            if(visit[u]==i)  
            {  
                ret=0;cnt=0;  
                visit[u]=-1;  
                for(v=next[u];v!=u;v=next[v])  
                {  
                    visit[v]=-1;  
                }  
                v=u;  
                do{  
                    pre[cnt]=len[v];  
                    sa[cnt++]=handle(v);  
                    v=next[v];  
                }while(v!=u);  
                ans+=dp(cnt);  
            }  
        }  
    }  
    cout<<ans;  
    return 0;  
}  
