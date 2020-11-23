//
// Created by Kain Zhang on 2020/9/7.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e4 + 5;

struct Node {
    int sum, drop;
};

vector<Node> vec(mxN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, cnt = 0, tmp = 0, S = 0, dt = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int m, t;
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> t;
            if (t > 0) {
                if (j) {
                    vec[i].drop += vec[i].sum - t;
                }
                vec[i].sum = t;
            } else {
                vec[i].sum += t;
            }
        }
        S += vec[i].sum;
        if (vec[i].drop) {
            tmp++;
            dt++;
            if (tmp > 2) {
                cnt++;
            }
        } else {
            tmp = 0;
        }
    }
    if (tmp >= 1 && vec[0].drop && vec[1].drop ) {
        cnt++;
    }
    if (tmp > 1 && vec[0].drop) {
        cnt++;
    }
    cout << S  << " " << dt << " " << cnt;
}

/*
4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0
 */