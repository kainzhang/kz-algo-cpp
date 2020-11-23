//
// Created by Kain Zhang on 2020/11/23.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int MIN = *min_element(nums.begin(), nums.end()), res = 0;
        for (int &it : nums) {
            res += it - MIN;
        }
        return res;
    }
};

int main() {
//    vector<int> vec = {1, 2, 3};
    vector<int> vec = {1, 1, 2147483647};
    cout << Solution().minMoves(vec);
}