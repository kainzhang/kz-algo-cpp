//
// Created by LOKKA on 2020/7/16.
//

#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b < b + a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<string> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), cmp);
    int flag = 0;
    for (int i = 0; i < N; i++) {
        if (!flag) {
            int num = stoi(v[i]);
            if (!num) continue;
            flag++;
            cout << num;
        } else {
            cout << v[i];
        }
    }
    if (!flag) cout << "0";
    cout << endl;
}
