//
// Created by LOKKA on 2020/5/17.
// BB-01-Backpack

#include <bits/stdc++.h>
using namespace std;

struct Herb {
    int tim, val;   // 时间，价值
    bool operator > (const Herb &x) const {
        return (val * 1.0 / tim) > (x.val * 1.0 / x.tim);
    }
};

struct Node {
    int nxt, sumT, sumV;    // 下一药草的序号 当前总时间 当前总价值
    double maxV;    // 该结点的上界
    bool operator < (const Node &x) const {
        return maxV < x.maxV;   // 优先队列内按上界从高到低排序
    }
};

int T, M;
vector<Herb> hrbs;
priority_queue<Node> que;

double bound(int i, int sumT, int sumV) {
    double res = sumV;
    int leftT = T - sumT;   // 剩余时间
    while (i < M && hrbs[i].tim <= leftT) { // 在时间允许的条件下不断放入
        leftT -= hrbs[i].tim;
        sumV += hrbs[i].val;
        i++;
    }
    if (i < M) {
        res = sumV + leftT * (hrbs[i].val * 1.0 / hrbs[i].tim);
    }
    return res;
}

int solve() {
    int res = 0;
    Node r = {0, 0, 0, bound(0, 0, 0)};
    que.push(r);    // 放入根结点
    while (que.top().maxV > res) {  // 堆顶结点的上界大于已知
        Node n = que.top();
        que.pop();
        if (n.nxt == M) {
            res = max(res, n.sumV); // 获取实际解
        } else {
            Node n2 = n;    // 复制一个
            if (n.sumT + hrbs[n.nxt].tim <= T) {    // 超时剪掉
                n.maxV = bound(n.nxt, n.sumT, n.sumV);   // 放入当前草药时的上界
                if (n.maxV > res) {
                    n.sumT += hrbs[n.nxt].tim;  // 修改当前时间
                    n.sumV += hrbs[n.nxt].val;  // 修改当前价值
                    n.nxt++;
                    que.push(n);
                }
            }
            n2.maxV = bound(n2.nxt + 1, n2.sumT, n2.sumV);   // 不放当前草药时的上界
            if (n.maxV > res) { // 上界小于当前已知最优解则剪枝
                n2.nxt++;
                que.push(n2);
            }
        }
    }
    return res;
}

int main() {
    scanf("%d %d", &T, &M);
    Herb h;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &h.tim, &h.val);
        hrbs.push_back(h);
    }
    sort(hrbs.begin(), hrbs.end(), greater<Herb>());    // 按单位时间价值排序
    cout << solve() << endl;
}