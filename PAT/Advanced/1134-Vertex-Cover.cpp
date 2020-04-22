//
// Created by LOKKA on 2020/4/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K, n, t;
    scanf("%d %d", &N, &M);
    vector<pair<int, int>> mp(M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &mp[i].first, &mp[i].second);
    }
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &n);
        vector<bool> hash(M, false);
        while (n--) {
            scanf("%d", &t);
            hash[t] = true;
        }
        bool flag = true;
        for (int i = 0; i < M; i++) {
            if (hash[mp[i].first] == false && hash[mp[i].second] == false) {
                flag = false;
                break;
            }
        }
        cout << (flag ? "Yes" : "No") << endl;
    }
}