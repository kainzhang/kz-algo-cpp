//
// Created by LOKKA on 2020/7/9.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 75;

int G[mxN][3], post[mxN], in[mxN];
vector<int> res[mxN];

int build_tree(int pL, int pR, int iL, int iR) {
    if (pL > pR) return -1;
    int k = iL;
    while (k <= iR) {
        if (in[k] == post[pR]) break;
        k++;
    }
    int numleft = k - iL;
    G[post[pR]][0] = build_tree(pL, pL + numleft - 1, iL, k - 1);
    G[post[pR]][1] = build_tree(pL + numleft, pR - 1, k + 1, iR);
    return post[pR];
}

// DFS 按层保存数据
int mxL = -1;
void get_res(int r, int lyr) {
    mxL = max(mxL, lyr);
    res[lyr].push_back(r);
    if (G[r][0] > -1) get_res(G[r][0], lyr + 1);
    if (G[r][1] > -1) get_res(G[r][1], lyr + 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> in[i];
    for (int i = 0; i < N; i++) cin >> post[i];
    int root = build_tree(0, N - 1, 0, N - 1);
    get_res(root, 0);

    // 0, 2, 4 ... 倒序输出
    // 1, 3, 5 ... 正序输出
    int cnt = 0;
    for (int i = 0; i <= mxL; i++) {
        int len = res[i].size();
        if (i & 1) {
            for (int j = 0; j < len; j++) {
                cout << " " << res[i][j];
            }
        } else {
            for (int j = len - 1; j >=0 ; j--) {
                if (cnt++) cout << " ";
                cout << res[i][j];
            }
        }
    }
}
