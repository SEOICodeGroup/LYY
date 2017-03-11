const int maxn = 10000;;
int next[maxn], extend[maxn];

void Getnext(char *str) {
    int i = 0, j, a, len = strlen(str);
    next[0] = len;  //自己等于自己
    while(str[i] == str[i + 1] && i + 1 < len) i++;//计算next[1]
    next[1] = i;
    a = 1;
    for(i = 2; i < len; i ++) {
        if(next[i - a] + i < next[a] + a) next[i] = next[i - a];
        else {
            j = next[a] + a - i;
            if(j < 0) j = 0;    //如果i > a + next[a] 则要从头开始匹配
            while(i + j < len && str[j] == str[j + i]) j ++;
            next[i] = j;
            a = i;
        }
    }
}

void ExKMP(char *s1, char *s2) {
    int i = 0, j, a, l1 = strlen(s1), l2 = strlen(s2);
    Getnext(s2);
    while(s1[i] == s2[i] && i < l2 && i < l1) i++;
    extend[0] = i;
    a = 0;  //初始化a 的位置
    for(i = 1; i < l1; i ++) {
        if(next[i - a] + i < next[a] + a) extend[i] = next[i - a];
        else {
            j = extend[a] + a - i;
            if(j < 0) j = 0;
            while(i + j < l1 && j < l2 && s1[j + i] == s2[j]) j ++;
            extend[i] = j;
            a = i;
        }
    }
}