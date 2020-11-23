//
// Created by LOKKA on 2020/4/7.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isValid(int row, int col, vector<int> &pos) {
        for (int i = 0; i < row; i++) {
            if (col == pos[i] || abs(row - i) == abs(pos[i] - col))
                return false;
        }
        return true;
    }
    void dfs(int row, int n, vector<int> &pos, int &res) {
        if (row == n) {
            res++;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, pos)) {
                pos[row] = i;
                dfs(row + 1, n, pos, res);
                pos[row] = -1;
            }
        }
    }
    int totalNQueens(int n) {
        vector<int> pos(n, -1);
        int res = 0;
        dfs(0, n, pos, res);
        return res;
    }
};

int main() {
    Solution *a = new Solution;
    int n;
    cin >> n;
    cout << a->totalNQueens(n) << endl;
}