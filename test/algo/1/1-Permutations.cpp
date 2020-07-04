//
// Created by LOKKA on 2020/5/17.
//

#include <bits/stdc++.h>
using namespace std;

// 含去重
void dfs(vector<int>& tmp, vector<int>& nums, vector<vector<int>>& res, vector<int>& vis) {
    if(tmp.size() == nums.size()) {
        res.push_back(tmp);
        return;
    }
    int len = nums.size();
    for(int i = 0; i < len; i++) {
        if(vis[i]) continue;
        if(i && nums[i] == nums[i-1] && !vis[i-1]) continue;
        tmp.push_back(nums[i]);
        vis[i] = 1;
        dfs(tmp, nums, res, vis);
        tmp.pop_back();
        vis[i] = 0;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    vector<int> vis(nums.size(), 0);
    vector<int> tmp;
    dfs(tmp, nums, res, vis);
    return res;
}

int main() {
    vector<int> nums = {1, 3, 5};
    vector<vector<int>> ans = permuteUnique(nums);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}