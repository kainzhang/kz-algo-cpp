//
// Created by LOKKA on 2020/7/13.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> pre, post, in;
bool is_unique = true;

void get_in(int preL, int preR, int postL, int postR) {
    if (preL == preR) {
        in.push_back(pre[preL]);
        return;
    }
    if (pre[preL] == post[postR]) {
        int i = preL + 1;
        while (i <= preR && pre[i] != post[postR - 1]) i++;
        if (i - preL > 1) {
            get_in(preL + 1, i - 1, postL, postL + (i - preL - 1) - 1);
        } else {
            is_unique = false;
        }
        in.push_back(post[postR]);
        get_in(i, preR, postL + (i - preL -1), postR - 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    pre.resize(N), post.resize(N);
    for (int i = 0; i < N; i++) cin >> pre[i];
    for (int i = 0; i < N; i++) cin >> post[i];
    get_in(0, N - 1, 0, N - 1);
    cout << (is_unique ? "Yes" : "No") << endl;
    cout << in[0];
    int len = in.size();
    for (int i = 1; i < len; i++) {
        cout << " " << in[i];
    }
    cout << endl;
}
