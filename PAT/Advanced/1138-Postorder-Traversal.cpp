//
// Created by LOKKA on 2020/7/12.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> pre, in;

int flag = 0;
void build_tree(int preL, int preR, int inL, int inR) {
    if (preL > preR || flag) return;
    int k = inL;
    while (k <= inR) {
        if (in[k] == pre[preL]) break;
        k++;
    }
    int numleft = k - inL;
    build_tree(preL + 1, preL + numleft, inL, k - 1);
    build_tree(preL + numleft + 1, preR, k + 1, inR);
    if (!flag) {
        cout << pre[preL] << endl;
        flag++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    pre.resize(N), in.resize(N);
    for (int i = 0; i < N; i++) cin >> pre[i];
    for (int i = 0; i < N; i++) cin >> in[i];
    build_tree(0, N - 1, 0, N - 1);
}
