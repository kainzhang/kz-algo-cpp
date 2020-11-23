//
// Created by LOKKA on 2020/4/2.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int thirdMax(vector<int>& nums) {
    long long first = LONG_LONG_MIN, second = LONG_LONG_MIN, third = LONG_LONG_MIN;
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        if (nums[i] > first) {
            third = second;
            second = first;
            first = nums[i];
        } else if (nums[i] > second && nums[i] < first) {
            third = second;
            second = nums[i];
        } else if (nums[i] > third && nums[i] < second) {
            third = nums[i];
        }
    }
    if (third != LONG_LONG_MIN)
        return third;
    return first;
}

int main() {
    vector<int> a = {1,2,2,5,3,5};
    //vector<int> a = {1,2,-2147483648};
    cout << thirdMax(a) << endl;
}