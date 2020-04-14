//
// Created by LOKKA on 2020/4/8.
//

#include <iostream>

using namespace std;
int n, bd[10][10], res = 0;

bool isValid(int row, int col, int q) {  // q 为皇后类型
    for (int r = row - 1, t = 1; r >= 0; r--, t++) {
        if (bd[r][col] == q
            || (col - t >= 0 && bd[r][col - t] == q)
            || (col + t < n && bd[r][col + t] == q)) {
            return false;
        }
    }
    return true;
}

void dfs(int row, int q) {
    if (q == 4) {
        res++;
        return;
    } else if (row == n) {
        dfs(0, q + 1);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (bd[row][col] == 0 || bd[row][col] == 2) continue;
        if (isValid(row, col, q)) {
            bd[row][col] = q;
            dfs(row + 1, q);
            bd[row][col] = 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &bd[i][j]);
    dfs(0, 2);
    cout << res << endl;
}