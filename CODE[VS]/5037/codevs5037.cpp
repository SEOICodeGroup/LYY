#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int Max = 200000;
int S[Max + 5], Clocks[Max + 5], Lazy[450], Num[450][Max + 5], N_C;
int N, M, Mod;

void input() {
    scanf("%d %d %d", &N, &M, &Mod);
    N_C = floor(sqrt(N));
    for(int i = 1; i <= N; i ++) {scanf("%d", &S[i]); S[i] %= Mod;}
    int tot = 0;
    for(int i = 1; i <= N; i ++) {
        if(i % N_C == 0) tot ++;
        Num[tot][S[i]] ++;
        Clocks[i] = tot;
    }
    //for(int i = 1; i <= N; i ++) printf("%lld ", Clocks[i]);
}
void Add() {
    int L, R, x;
    scanf("%d %d %d", &L, &R, &x);
    if(Clocks[L] == Clocks[R]) {
        for(int i = L; i <= R; i ++) {
            Num[Clocks[L]][(S[i] + x) % Mod] ++;
            Num[Clocks[L]][(S[i]) % Mod] --;
            S[i] = (S[i] + x) % Mod;
        }
        return;
    } else {
        for(int i = L; Clocks[i] == Clocks[L]; i ++) {
            Num[Clocks[i]][(S[i] + x) % Mod] ++;
            Num[Clocks[i]][(S[i]) % Mod] --;
            S[i] = (S[i] + x) % Mod;
        }
        for(int i = R; Clocks[i] == Clocks[R]; i --) {
            Num[Clocks[i]][(S[i] + x) % Mod] ++;
            Num[Clocks[i]][(S[i]) % Mod] --;
            S[i] = (S[i] + x) % Mod;
        }
        for(int i = Clocks[L] + 1; i <= Clocks[R] - 1; i ++) Lazy[i] = (Lazy[i] + x) % Mod; 
    }
}
void Cnt() {
    int L, R, res = 0;
    scanf("%d %d", &L, &R);
    if(Clocks[L] == Clocks[R]) {
        for(int i = L; i <= R; i ++) if(!((S[i] + Lazy[Clocks[L]]) % Mod)) res ++;
    } else {
        for(int i = L; Clocks[i] == Clocks[L]; i ++) if(!((S[i] + Lazy[Clocks[L]]) % Mod)) res ++;
        for(int i = R; Clocks[i] == Clocks[R]; i --) if(!((S[i] + Lazy[Clocks[R]]) % Mod)) res ++;
        for(int i = Clocks[L] + 1; i <= Clocks[R] - 1; i ++) res += Num[i][(Mod - Lazy[i]) % Mod];
    }
    printf("%d\n", res);
}
void solve() {
    char order[10];
    while(M --) {
        scanf("%s", order);
        if(order[0] == 'a') Add();
        if(order[0] == 'c') Cnt();
    }    
}
int main() {
    input();
    solve();
    return 0;
}