//
// Created by LOKKA on 2020/4/8.
//

#include <iostream>

using namespace std;
int n = 8, bd[10][10], res = 0;

bool isValid(int row, int col) {
    for (int r = row - 1, t = 1; r >= 0; r--, t++) {
        if (bd[r][col] == -1
            || (col - t >= 0 && bd[r][col - t] == -1)
            || (col + t < n && bd[r][col + t] == -1)) {
            return false;
        }
    }
    return true;
}

void dfs(int row, int sum) {
    if (row == n) {
        res = max(res, sum);
        return;
    }
    for (int col = 0; col < n; col++) {
        if (isValid(row, col)) {
            int tmp = bd[row][col];
            bd[row][col] = -1;
            dfs(row + 1, sum + tmp);
            bd[row][col] = tmp;
        }
    }
}

int main() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &bd[i][j]);

    dfs(0, 0);
    cout << res << endl;
}