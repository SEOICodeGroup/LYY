void PREVISIT(int u) { pre[u] = ++dfs_clocks; }
void POSTVISIT(int u) { post[u] = ++dfs_clocks; }

int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clocks;
    int child = 0;
    for(int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i];
        if(!pre[v]) {                   //没有访问过v
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowu, lowv);     //用后代的low函数更新u的函数
            if(lowv >= pre[u]) {
                iscut[u] = true;
            }
            if(lowv > pre[u]) {
                isbridge[id[u][v]] = true;
            }
        }
        else if(pre[v] < pre[u] && v != fa) {
            lowu = min(lowu, pre[v]);
        }
    }
    if(fa < 0 && child == 1) iscut[u] = 0;
    low[u] = lowu;
    return lowu;
}