//
// Created by LOKKA on 2020/7/16.
//

#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<pair<int, int> > e;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        e.push_back(make_pair(a, b));
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        vector<int> v(N);
        set<int> c;
        for (int j = 0; j < N; j++) {
            cin >> v[j];
            c.insert(v[j]);
        }

        int flag = true;
        for (int i = 0; i < M; i++) {
            if (v[e[i].first] == v[e[i].second]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << c.size() << "-coloring" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
