//
// Created by Kain Zhang on 2020/11/23.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[1] < b[1];
        });
        int end = points[0][1], res = 1;
        for (auto &it : points) {
            if (it[0] > end) {
                res++;
                end = it[1];
            }
        }
        return res;
    }
};

int main() {
//    vector<vector<int>> vec = {
//            {10, 16}, {2, 8}, {1, 6}, {7, 12}
//    };

    vector<vector<int>> vec = {
            {9, 12}, {1, 10}, {4, 11}, {8, 12}, {3, 9}, {6, 9}, {6, 7}
    };

//    vector<vector<int>> vec = {
//            {1, 2}, {2, 3}, {3, 4}, {4, 5}
//    };

    int ans = Solution().findMinArrowShots(vec);
    cout << ans;
}