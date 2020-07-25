//
// Created by LOKKA on 2020/7/13.
//

#include <bits/stdc++.h>
using namespace std;

vector<int> v, post;
bool judgeM = false;

void get_post(int l, int r) {
    int i = l + 1, j = r;
    if (!judgeM) {
        while (i <= r && v[l] > v[i]) i++;
        while (j > l && v[l] <= v[j]) j--;
    } else {  // 镜像
        while (i <= r && v[l] <= v[i]) i++;
        while (j > l && v[l] > v[j]) j--;
    }
    if (i - j != 1) return;
    get_post(l + 1, j);
    get_post(i, r);
    post.push_back(v[l]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    get_post(0, N - 1);
    if (post.size() != N) {
        judgeM = true;
        post.clear();
        get_post(0, N - 1);
    }
    if (post.size() == N) {
        cout << "YES" << endl;
        cout << post[0];
        for (int i = 1; i < N; i++) {
            cout << " " << post[i];
        }
    } else {
        cout << "NO";
    }
}
