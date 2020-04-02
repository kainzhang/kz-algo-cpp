//
// Created by LOKKA on 2020/4/2.
//

#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

using namespace std;

int randPartition(vector<int>& nums, int lo, int hi) {
    int p = (round(1.0 * rand() / RAND_MAX * (hi - lo) + lo));
    swap(nums[p], nums[lo]);
    int tmp = nums[lo];
    while(lo < hi) {
        while(lo < hi && nums[hi] > tmp) hi--;
        nums[lo] = nums[hi];
        while(lo < hi && nums[lo] <= tmp) lo++;
        nums[hi] = nums[lo];
    }
    nums[lo] = tmp;
    return lo;
}

int randSelect(vector<int>& nums, int lo, int hi, int k) {
    if (lo == hi) return nums[lo];
    int p = randPartition(nums, lo, hi);
    int m = p - lo + 1;
    if (k == m) return nums[p];
    if (k < m)
        return randSelect(nums, lo, p - 1, k);
    else
        return randSelect(nums, p + 1, hi, k - m);
}

int findKthLargest(vector<int>& nums, int k) {
    srand((unsigned)time(NULL));
    return randSelect(nums, 0, nums.size() - 1, nums.size() - k + 1);
}

int main() {
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;

//    vector<int> nums = {3,2,3,1,2,4,5,5,6};
//    int k = 4;

    cout << findKthLargest(nums, k) << endl;
}