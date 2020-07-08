//
// Created by LOKKA on 2020/7/7.
//

#include <bits/stdc++.h>
using namespace std;

set<int> seq[55];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> M;
        while (M--) {
            int num;
            cin >> num;
            seq[i].insert(num);
        }
    }
    int K;
    cin >> K;
    while(K--) {
        int a, b, NC = 0;
        cin >> a >> b;
        for (auto &i : seq[a]) {
            if (seq[b].find(i) != seq[b].end()) {
                NC++;
            }
        }
        int NT = seq[a].size() + seq[b].size() - NC;
        printf("%.1f%\n", NC * 100.0 / NT);
    }
}
