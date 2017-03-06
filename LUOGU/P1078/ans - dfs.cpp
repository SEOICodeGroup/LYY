#include<cstdio>
#include<cstring>
int i,j,n,k,m,s,t,ans=16843009;
int c[101];
int matrix[101][101];
int ljma[101][101];
int u[10001],v[10001],d[10001];
bool learned[101]; //��¼ĳ���Ļ��Ƿ��ѱ�ѧ�� 
void dfs(int a, int dis)
{
    if (a == t) 
    {
        if (dis < ans) ans = dis;
        return;
    }
    if (dis >= ans) return;  //�����Լ�֦ 
    for (i=1; i<=n; i++)
      if (learned[c[i]]==0 && matrix[c[i]][c[a]]==0 && ljma[i][a] >= 1)
        {
            bool flag = 1;
	        for (j=1; j<=k; j++)
	          if (learned[j] == 1)
	            if (matrix[c[i]][j] == 1) { flag=0; break; } //ÿһ����ѧ�����Ļ������ܱ��ų� 
            if (flag==0) break;
            learned[c[i]] = 1;
            dfs(i,dis+ljma[i][a]);
            learned[c[i]] = 0;
        }
}
int main()
{
    memset(ljma,0,sizeof(ljma));
    memset(learned,0,sizeof(learned));
    scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
    for (i=1; i<=n; i++)
      scanf("%d",&c[i]);
    for (i=1; i<=k; i++)
      for (j=1; j<=k; j++)
        scanf("%d",&matrix[i][j]); //�����Ļ��ľ��� 
    for (i=1; i<=m; i++)
    {
      scanf("%d%d%d",&u[i],&v[i],&d[i]);
      if (ljma[u[i]][v[i]]>0 && ljma[u[i]][v[i]]>d[i] || ljma[u[i]][v[i]]==0)
      {
        ljma[u[i]][v[i]]=d[i]; //�Ƿ���·�� 
        ljma[v[i]][u[i]]=d[i];
      }
    }
    learned[c[s]]=1; 
    dfs(s,0);
    if (ans == 16843009) printf("-1");
    else printf("%d",ans);
    return 0;
}
