//
// Created by LOKKA on 2020/7/19.
//

#include <bits/stdc++.h>
using namespace std;

struct Node {
    string name;
    int ga, gm, gf, G;
    bool operator < (const Node &x) const {
        return (G == x.G ? name < x.name : G > x.G);
    }
};

map<string, int> mp;
vector<Node> vec;

/**
 *  期中期末分数存在 0 分的情况
 *  下标 (序号) 从 1 开始
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int P, M, N;
    cin >> P >> M >> N;
    string id;
    int num, idx = 1;
    for (int i = 0; i < P; i++) {
        cin >> id >> num;
        if (num >= 200) {
            vec.push_back(Node{id, num, -1, -1, 0});
            mp[id] = idx++;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> id >> num;
        if (mp[id]) vec[mp[id] - 1].gm = num;
    }
    for (int i = 0; i < N; i++) {
        cin >> id >> num;
        if (mp[id]) {
            vec[mp[id] - 1].gf = num;
            if (vec[mp[id] - 1].gm > vec[mp[id] - 1].gf) {
                vec[mp[id] - 1].G = vec[mp[id] - 1].gm * 0.4 + vec[mp[id] - 1].gf * 0.6 + 0.5;
            } else {
                vec[mp[id] - 1].G = vec[mp[id] - 1].gf;
            }
        }
    }
    sort(vec.begin(), vec.end());
    for (Node &i : vec) {
        if (i.G >= 60)
            printf("%s %d %d %d %d\n", i.name.c_str(), i.ga, i.gm, i.gf, i.G);
    }
}
