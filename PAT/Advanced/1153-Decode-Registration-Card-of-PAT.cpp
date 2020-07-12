//
// Created by LOKKA on 2020/7/12.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string s;
    int val;
    bool operator < (const Node &x) const {
        return val == x.val ? s < x.s : val > x.val;
    }
};

vector<Node> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i].s >> v[i].val;
    }
    for (int i = 1; i <= M; i++) {
        int num; string str;
        vector<Node> ans;
        cin >> num >> str;
        printf("Case %d: %d %s\n", i, num, str.c_str());
        switch(num) {
            case 1: {
                char sign = str[0];
                for (int j = 0; j < N; j++) {
                    if (v[j].s[0] == sign) {
                        ans.push_back(v[j]);
                    }
                }
                break;
            } case 2: {
                int cnt = 0, sum = 0;
                for (int j = 0; j < N; j++) {
                    if (v[j].s.substr(1, 3) == str) {
                        cnt++;
                        sum += v[j].val;
                    }
                }
                if (!cnt) {
                    printf("NA\n");
                } else {
                    printf("%d %d\n", cnt, sum);
                }
                continue;
            } case 3: {
                unordered_map<string, int> tmp;
                for (int j = 0; j < N; j++) {
                    string dd = v[j].s.substr(4, 6);
                    if (dd == str) {
                        tmp[v[j].s.substr(1, 3)]++;
                    }
                }
                for (auto &m : tmp) {
                    ans.push_back(Node{m.first, m.second});
                }
                break;
            }
        }
        int len = ans.size();
        if (!len) {
            printf("NA\n");
            continue;
        }
        sort(ans.begin(), ans.end());
        for (int j = 0; j < len; j++) {
            printf("%s %d\n", ans[j].s.c_str(), ans[j].val);
        }
    }
}
