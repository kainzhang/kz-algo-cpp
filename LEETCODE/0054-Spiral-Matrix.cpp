//
// Created by LOKKA on 2020/4/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int r1 = 0, r2 = matrix.size() - 1, r;
        int c1 = 0, c2 = matrix[0].size() - 1, c;
        while (1) {
            for (c = c1, r = r1; c <= c2; c++) {
                res.push_back(matrix[r][c]);
            }
            if (++r1 > r2) break;
            for (r = r1, c = c2; r <= r2; r++) {
                res.push_back(matrix[r][c]);
            }
            if (--c2 < c1) break;
            for (c = c2, r = r2; c >= c1; c--) {
                res.push_back(matrix[r][c]);
            }
            if (--r2 < r1) break;
            for (r = r2, c = c1; r >= r1; r--) {
                res.push_back(matrix[r][c]);
            }
            if (++c1 > c2) break;
        }
        return res;
    }
};

int main() {
//    vector<vector<int>> mat = {
//            {1, 2, 3},
//            {4, 5, 6},
//            {7, 8, 9}
//    };
    vector<vector<int>> mat = {
            {1, 2,  3,  4},
            {5, 6,  7,  8},
            {9, 10, 11, 12}
    };
    vector<int> ans = Solution().spiralOrder(mat);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}