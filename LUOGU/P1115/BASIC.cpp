#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdio>
using namespace std;
int main(){
    int N;
    cin >> N;
    long long ans = 0;
    long long now = 0;
    cin >> now;
    ans = now;
    long long min_ = 0;  //min_一定初值为0
    for(int i = 2; i<= N; i++)
    {
       
        int x;
        scanf("%d",&x); //输入
        now += x;
        ans = now-min_>ans?now-min_:ans;
        min_ = now<min_?now:min_;
       
    }
    cout << ans;
    return 0;
}

