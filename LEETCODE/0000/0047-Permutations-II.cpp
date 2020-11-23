//
// Created by LOKKA on 2020/4/6.
// dfs backtrace

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

// 使用 set
//void dfs(int cur ,vector<int>& nums, set<vector<int>>& res) {
//    if(cur == nums.size() - 1) {
//        res.insert(nums);
//        return;
//    }
//    for(int i = cur; i < nums.size(); i++) {
//        swap(nums[cur], nums[i]);
//        dfs(cur + 1, nums, res);
//        swap(nums[cur], nums[i]);
//    }
//}
//
//vector<vector<int>> permuteUnique(vector<int>& nums) {
//    set<vector<int>> res;
//    dfs(0, nums, res);
//    return vector<vector<int>> (res.begin(), res.end());
//}

void dfs(vector<int> &tmp, vector<int> &nums, vector<vector<int>> &res, vector<int> &vis) {
    if (tmp.size() == nums.size()) {
        res.push_back(tmp);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (vis[i]) continue;
        if (i && nums[i] == nums[i - 1] && !vis[i - 1]) continue;
        tmp.push_back(nums[i]);
        vis[i] = 1;
        dfs(tmp, nums, res, vis);
        tmp.pop_back();
        vis[i] = 0;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    vector<int> vis(nums.size(), 0);
    vector<int> tmp;
    dfs(tmp, nums, res, vis);
    return res;
}

int main() {
    vector<int> nums = {1, 1, 2};
    vector<vector<int>> ans = permuteUnique(nums);
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