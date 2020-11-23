//
// Created by Kain Zhang on 2020/9/7.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e3 + 5;

struct Node {
    int sum, cut;
};

vector<Node> vec(mxN);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, t, S = 0, mxC = INT_MIN, mxC_i = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> vec[i].sum;
        for (int j = 0; j < M; j++) {
            cin >> t;
            vec[i].cut += t;
        }
        S += vec[i].sum + vec[i].cut;
        if (abs(vec[i].cut) > mxC) {
            mxC = abs(vec[i].cut);
            mxC_i = i;
        }
    }
    cout << S << " " << mxC_i + 1 << " " << mxC;
}

/*
3 3
73 -8 -6 -4
76 -5 -10 -8
80 -6 -15 0
 */