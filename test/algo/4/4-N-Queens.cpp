//
// Created by LOKKA on 2020/4/7.
// DFS, Backtracking

#include <bits/stdc++.h>
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

    void dfs(vector<string>& bd, vector<int>& pos, int row, int n) {
        if(row == n) {
            res.push_back(bd);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(isValid(row, i, pos)) {
                bd[row][i] = 'Q';
                pos[row] = i;
                dfs(bd, pos, row + 1, n);
                bd[row][i] = '.';
                pos[row] = -1;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> bd(n, string(n, '.'));
        vector<int> pos(n, -1);
        dfs(bd, pos, 0, n);
        return res;
    }

private:
    vector<vector<string>> res;
};

int main() {
    int n;
    cin >> n;
    vector<vector<string>> ans = Solution().solveNQueens(n);
    vector<vector<string>>::iterator it;
    for (it = ans.begin(); it != ans.end(); it++) {
        vector<string>::iterator it2;
        for (it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2;
            cout << endl;
        }
        cout << endl;
    }
}