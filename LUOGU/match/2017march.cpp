#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000;
int A[MAXN];
long long C[MAXN];
int b[MAXN];

int main() { 
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> C[i];        //读入，改变编号
        A[i]--;
    }
    for (int i = 0; i < n; i++) {
        b[i] = -1;                  //标记初始化
    }
    bool F = 0;
    for (int i = 0; i < n; i++) {
        if (b[i] != -1) {
            continue;              //找到没有访问过的点
        }
        int j = i;
        while (b[j] == -1) {       //顺着链往下走，找环
            b[j] = i;
            j = A[j];
        }
        if (b[j] == i) {
            int C = 0;
            while (b[j] != -2) {    //把环上的标记置为-2
                b[j] = -2;
                j = A[j];
                C++;
            }
            if (C == n) {
                F = 1;
            }
        }
    }
    long long ans = 0ll;
    if (!F) {
        for (int i = 0; i < n; i++) {
            ans += C[i];                //累加C[i] ans当前为所有边的全值和
        }
        static long long M1[MAXN] = {0}, M2[MAXN] = {0}; //M1所有 M2链
        for (int i = 0; i < n; i++) {
            M1[A[i]] = max(M1[A[i]], C[i]); //刨链贪心留下全值最大的点
            //更改当前节点所需要的费用
            if (b[i] != -2) {
                M2[A[i]] = max(M2[A[i]], C[i]); //不在环上
            }
        }
        for (int i = 0; i < n; i++) {
            ans -= M1[i];               //把最长链减去，剩下的都是改变的边
        }
        for(int i=0;i<n;i++) printf("%d %d\n",M1[i],M2[i]);     //每个节点的出度最多只能是2 
        for (int i = 0; i < n; i++) {
            if (b[i] != -2) {           //枚举环
                continue;
            }
            long long M = 10000000000ll;
            int j = i;
            while (b[j] == -2) {
                M = min(M, M1[j] - M2[j]);      //枚举每个点破开链
                b[j] = -3;                      //重复计算？
                j = A[j];
            }
            ans += M;
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}