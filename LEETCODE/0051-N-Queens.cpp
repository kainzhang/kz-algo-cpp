//
// Created by LOKKA on 2020/4/7.
// DFS, Backtracking

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

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

    void dfs(int row, int n, vector<int> &pos, string &line) {
        if (row == n) {
            res.push_back(tmp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, pos)) {
                line[i] = 'Q';
                tmp.push_back(line);
                line[i] = '.';
                pos[row] = i;
                dfs(row + 1, n, pos, line);
                pos[row] = -1;
                tmp.pop_back();
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string line(n, '.');
        vector<int> pos(n, -1);
        dfs(0, n, pos, line);
        return res;
    }

private:
    vector<vector<string>> res;
    vector<string> tmp;
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
        }
        cout << endl;
    }
}