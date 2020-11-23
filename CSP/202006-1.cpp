//
// Created by Kain Zhang on 2020/8/22.
// 线性分类器

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y;
    char type;
};
vector<Node> vec;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y;
    char type;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> type;
        vec.push_back(Node{x, y, type});
    }
    int t0, t1, t2;
    while (m--) {
        cin >> t0 >> t1 >> t2;
        int a = 0, b = 0;
        for (Node &i : vec) {
            int tmp = t0 + t1 * i.x + t2 * i.y;
            tmp = tmp > 0 ? 1 : -1;
            if (i.type == 'A') a += tmp;
            else b += tmp;
        }
        cout << (abs(a) + abs(b) == n ? "Yes" : "No") << endl;
    }
}

/*
INPUT:
9 3
1 1 A
1 0 A
1 -1 A
2 2 B
2 3 B
0 1 A
3 1 B
1 3 B
2 0 A
0 2 -3
-3 0 2
-3 1 1
 */


