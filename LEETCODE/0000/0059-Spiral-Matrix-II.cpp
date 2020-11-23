//
// Created by LOKKA on 2020/4/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int r1 = 0, r2 = n - 1, r;
        int c1 = 0, c2 = n - 1, c;
        int idx = 0;
        while (1) {
            for (c = c1, r = r1; c <= c2; c++) {
                res[r][c] = ++idx;
            }
            if (++r1 > r2) break;
            for (r = r1, c = c2; r <= r2; r++) {
                res[r][c] = ++idx;
            }
            if (--c2 < c1) break;
            for (c = c2, r = r2; c >= c1; c--) {
                res[r][c] = ++idx;
            }
            if (--r2 < r1) break;
            for (r = r2, c = c1; r >= r1; r--) {
                res[r][c] = ++idx;
            }
            if (++c1 > c2) break;
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<vector<int>> ans = Solution().generateMatrix(n);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}