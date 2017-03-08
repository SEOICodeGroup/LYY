#include <cstdio>
using namespace std;
const int maxn = 100000;

struct node {
    int nxt[26];
    int fail, cnt;
}nod[maxn];
int tot, root;
int que[maxn], head, tail;

char A[maxn];

inline void insert(char *s) {
    int now = root;
    for (int i = 0; s[i] != '\0'; i ++) {
        int x = s[i] -'a';
        if(nod[now].nxt[x] == 0) nod[now].nxt[x] = tot++;
        now = nod[now].nxt[x];
    }
    return;
}

inline void build() {
    for (int i = 0; i < 26; i ++) if (nod[root].nxt[i] != 0) {
        int p = nod[root].nxt[i];
        nod[p].fail = root;
        que[tail++] = p;
    }

    while (head < tail) {
        int p = que[head++];
        for (int i = 0; i < 26; i ++) if (nod[p].nxt[i]) {
            int x = nod[p].nxt[i];
            int j = nod[p].fail;
            while(j != root && nod[j].nxt[i] == 0) j = nod[j].fail;
            if(nod[j].nxt[i]) j = nod[j].nxt[i];
            nod[x].fail = j;
            que[tail++] = x;
        }
    }
    return;
}

inline void solve(char *s) {
    int now = root;
    for (int i = 0; s[i] != '\0'; ++i) {
        int x = s[i] - 'a';
        while(now != root && nod[now].nxt[x] == 0) now = nod[now].fail;
        if (nod[now].nxt[x]) now = nod[now].nxt[x];
        ++nod[now].cnt;
    }

    for (int i = tail - 1; i >= 0; --i) {
        int p = nod[que[i]].fail;
        nod[p].cnt += nod[que[i]].cnt;
    }
    return;
}