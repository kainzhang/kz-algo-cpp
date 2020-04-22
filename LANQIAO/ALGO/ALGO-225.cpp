//
// Created by LOKKA on 2020/4/5.
// 石子游戏（贪心、优先队列

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
typedef unsigned long long UL;

//int main() {
//    int n;
//    scanf("%d", &n);
//    UL *s = new UL[n];
//    for(int i = 0; i < n; i++)
//        scanf("%lld", &s[i]);
//
//    sort(s, s + n);
//    UL ans = 0;
//    for(int i = n - 1; i > 0; i--) {
//        ans += (s[i] + 1) * (s[i - 1] + 1);
//        s[i - 1] += s[i];
//    }
//    cout << ans << endl;
//}

int main() {
    int n;
    UL t;
    scanf("%d", &n);
    priority_queue<UL, vector<UL>, less<UL> > que;
    for (int i = 0; i < n; i++) {
        scanf("%lld", &t);
        que.push(t);
    }
    UL ans = 0, a, b = 0;
    while (que.size()) {
        a = que.top();
        que.pop();
        if (!b) {
            b = que.top();
            que.pop();
        }
        ans += (a + 1) * (b + 1);
        b += a;
    }
    cout << ans << endl;
}