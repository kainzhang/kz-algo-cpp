//
// Created by LOKKA on 2020/7/14.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> pre, in;
stack<int> stk;

/**
 *  通过 先序 和 中序 获取中序
 */

int flag = 0;
void buildTree(int preL, int preR, int inL, int inR) {
    if (preL > preR) return;
    int k = inL;
    while (k <= inR) {
        if (in[k] == pre[preL]) break;
        k++;
    }
    buildTree(preL + 1, preL + k - inL, inL, k - 1);
    buildTree(preL + k - inL + 1, preR, k + 1, inR);
    if (flag++) cout << " ";
    cout << pre[preL];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, cnt = 0;
    cin >> N;
    while(true) {
        if (cnt == N && stk.empty()) break;  // 结束输入 条件
        string cmd;
        cin >> cmd;
        if (cmd == "Push") {  // push 为先序
            int num;
            cin >> num;
            pre.push_back(num);
            stk.push(num);
            cnt++;
        } else {  // pop 为中序
            in.push_back(stk.top());
            stk.pop();
        }
    }
    buildTree(0, N - 1, 0, N - 1);
}
