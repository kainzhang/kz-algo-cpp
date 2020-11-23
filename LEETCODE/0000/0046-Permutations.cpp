//
// Created by LOKKA on 2020/4/6.
// dfs

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int cur, vector<int> &nums, vector<vector<int>> &res) {
    if (cur == nums.size() - 1) {
        res.push_back(nums);
        return;
    }
    for (int i = cur; i < nums.size(); i++) {
        swap(nums[cur], nums[i]);
        dfs(cur + 1, nums, res);
        swap(nums[cur], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<vector<int>> res;
    dfs(0, nums, res);
    return res;
}

//vector<vector<int>> permute(vector<int>& nums) {
//    vector<vector<int>> res;
//    sort(nums.begin(), nums.end());
//    do {
//        res.push_back(nums);
//    } while(next_permutation(nums.begin(), nums.end()));
//    return res;
//}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++) {
        cout << "[";
        for (int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j];
            if (j < ans[0].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i < ans.size() - 1)
            cout << ",";
        cout << endl;
    }
}