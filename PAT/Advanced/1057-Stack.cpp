//
// Created by LOKKA on 2020/7/16.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e5 + 10;
const int sqrN = 1e2;

stack<int> stk;
vector<int> blk(mxN), tb(mxN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, p = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;
        if (cmd[1] == 'u') {
            int num;
            cin >> num;
            stk.push(num);
            blk[num / sqrN]++;
            tb[num]++;
        } else {
            if (stk.empty()) {
                printf("Invalid\n");
            } else {
                if (cmd[1] == 'e') {
                    int mid, cnt = 0, idx = 0, len = stk.size();
                    if (len & 1) mid = (len + 1) / 2;
                    else mid = len / 2;

                    while (cnt + blk[idx] < mid) {
                        cnt += blk[idx++];
                    }

                    idx *= sqrN;
                    while (cnt + tb[idx] < mid) {
                        cnt += tb[idx++];
                    }
                    printf("%d\n", idx);
                } else {
                    int t = stk.top();
                    stk.pop();
                    printf("%d\n", t);
                    blk[t / sqrN]--;
                    tb[t]--;
                }
            }
        }
    }
}
