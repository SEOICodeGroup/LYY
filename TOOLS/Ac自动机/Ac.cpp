#include <cstdio>
#include <cstring>
using namespace std;

#define MAXC 26 // 字符集的元素个数

struct AcNode {
    AcNode *fail;
    AcNode *next[MAXC];

    //非必需数据
    int id;     //节点编号
    int val;    // 当前结点和它的fail指针指向结点的结尾单词信息的集合
    int cnt;    //计算单词出现数量

    void reset(int _id) {
        id = _id;
        cnt = 0;
        val = 0;
        fail = NULL;
        memset(next, 0, sizeof(next));
    }

    //状态机中接收态的概念
    //模式串为不能出现的时候才会有接受态
    bool isReceiving() {
        return val != 0;
    }
};

struct AcAutoman {
    AcNode* nodes[MAXQ];    //结点缓存，避免结点重复申请和释放，节省时间
    int nodesMax;           //缓存区大小，永远是递增的
    AcNode* root;           //根节点指针
    int nodeCount;          //节点总数

    //数据相关结构
    int ID[256], IDSize;    //节点上字母的简单Hash，使得编号在数组中连续

    //队列相关结构
    AcNodeQueue Q;

    AcAutoman() {
        nodesMax = 0;
    }

    void init() {
        nodeCount = 0;
        IDSize = 0;
        root = getNode();
        memset(ID, -1, sizeof(ID));
    }

    AcNode *getNode() {
        //内存池已满，需要申请新的节点
        if(nodeCount >= nodesMax) {
            nodes[nodesMax++] = new AcNode();
        }
        AcNode *p = nodes[nodeCount];
        p -> reset(nodeCount++);
        return p;
    }

    //获取字母对应的ID
    int getCharID(unsigned char c, int needcreate) {
        if(!needcreate) return ID[c];
        if(ID[c] == -1) ID[c] = IDSize++;
        return ID[c];
    }
};

void AcAutoman::insert(char *str, int val) {
    AcNode *p = root;
    int id;
    for(int i = 0; str[i]; i ++) {
        //获得字母对应的hashID
        id = getCharID(str[i], true);
        if(p->next[id] == NULL) p->next[id] = getNode();
        p = p->next[id];
    }
    p->val |= val;
    p->cnt++;
}

void construct_tire() {
    AcNode *now, *son, *tmp;

    root->fail = NULL;
    Q.clear();
    Q.push(root);

    //逐层计算每一层的节点的fail指针
    //当每个结点计算完毕，保证它所有的后继都已经计算出来了
    while (!Q.empty()) {
        now = Q.pop();
        if(now->fail) {
            //这里需要视情况而定
            //目的是将fail指针的状态信息传递给当前节点
            //now->val +=now ->fail->fail ....
            if(now->isReceiving()) {
                for(int i = 0; i < MAXC; i ++) {
                    now->next = now;
                }
                continue;
            }
        }
        //首先，我们把当前结点now的i号后继记为son[i]
        //1）如果son[i]不存在，将它指向当前结点now的fail指针指向的结点的i号后继（保证一定计算出来）
        //2）如果son[i]存在，将它的fail指针指向 当前结点now的fail指针指向结点的i号后继（保证一定计算出来）
        for(int i = 0; i < MAXC; i ++) {
            son = now -> next[i];
            tmp = (now == root)? root: now->fail->next[i];
            if(son == NULL) {
                now->next[i] = tmp;
            } else {
                son->fail = tmp;
                Q.push(son);
            }
        }
    }
}

int query_str(char *str) {
    AcNode *p = root, *tmp = NULL;
    int id, cnt = 0;
    for(int i = 0; str[i]; i ++) {
        id = getCharID(str[i], false);
        if(id == -1) {
            //当前单词从来没有出现过， 直接回到匹配之初
            p = root;
            continue;
        }
        p = p->next[id];
        tem = p;
        while(tmp != root && tmp->cnt != -1) {
            if(tmp -> cnt) {
                //找到一个字串以tmp节点结尾
                //不同题目不同
                //有的是统计字串数目，有的则是输出字串位置
                cnt += tmp->cnt;
                tmp->cnt = -1;
            }
            tmp = tmp->fail;
        }
        return cnt;
    }
}