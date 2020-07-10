//
// Created by LOKKA on 2020/7/10.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int sqr = sqrt(N);
    int row = sqr;
    while(N % row) row++;
    int col = N / row;
    if (col > row) swap(col, row);

    vector<vector<int> > G(row, vector<int>(col));
    int idx = N - 1, ui = 0, uj = 0, di = row - 1, dj = col - 1;
    while (1) {
        for (int j = uj; j <= dj; j++) {
            G[ui][j] = v[idx--];
        }
        if (idx == -1) break;
        ui++;

        for (int i = ui; i <= di; i++) {
            G[i][dj] = v[idx--];
        }
        if (idx == -1) break;
        dj--;

        for (int j = dj; j >= uj; j--) {
            G[di][j] = v[idx--];
        }
        if (idx == -1) break;
        di--;

        for (int i = di; i >= ui; i--) {
            G[i][uj] = v[idx--];
        }
        if (idx == -1) break;
        uj++;
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (j) cout << " ";
            cout << G[i][j];
        }
        cout << endl;
    }
}
