//
// Created by Kain Zhang on 2020/11/16.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return (a[0] == b[0] ? a[1] < b[1] : a[0] > b[0]);
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> res;
        for (auto& it : people) {
            res.insert(res.begin() + it[1], it);
        }
        return res;
    }
};

int main() {
    vector<vector<int>> vec = {
            {7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}
    };
    vector<vector<int>> ans = Solution().reconstructQueue(vec);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}