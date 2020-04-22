//
// Created by LOKKA on 2020/4/22.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> nums;

bool isPalindrome() {
    int len = nums.size();
    for (int i = 0; i <= len / 2; i++) {
        if (nums[i] != nums[len - i - 1])
            return false;
    }
    return true;
}

void radixFunc(int x, int b) {
    while (x) {
        nums.push_back(x % b);
        x /= b;
    }
}

int main() {
    int N, b;
    cin >> N >> b;
    radixFunc(N, b);
    cout << (isPalindrome() ? "Yes" : "No") << endl;
    int len = nums.size();
    for (int i = len - 1; i > 0; i--)
        cout << nums[i] << " ";
    cout << nums[0] << endl;
}