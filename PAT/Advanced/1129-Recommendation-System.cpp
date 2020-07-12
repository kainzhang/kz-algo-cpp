//
// Created by LOKKA on 2020/7/11.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, cnt;
    bool operator < (const Node &x) const {
        if (cnt == x.cnt)
            return val < x.val;
        return cnt > x.cnt;
    }
};

set<Node> res;
unordered_map<int, int> mp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    cin >> N >> K;
    while (N--) {
        int num;
        cin >> num;
        if (!res.empty()) {
            cout << num << ":";
            int flag = 0;
            for (auto &i : res) {
                if (flag++ == K) break;
                cout << " " << i.val;
            }
            cout << endl;
        }
        auto it = res.find(Node{num, mp[num]});
        if (it != res.end())
            res.erase(it);
        mp[num]++;
        res.insert(Node{num, mp[num]});
    }
}
