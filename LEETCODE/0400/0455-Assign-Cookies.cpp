//
// Created by Kain Zhang on 2020/11/23.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), less<int>());
        sort(s.begin(), s.end(), less<int>());
        int res = 0;
        for (int i = 0, j = 0; i < g.size() && j < s.size(); j++) {
            if (s[j] >= g[i]) {
                res++;
                i++;
            }
        }
        return res;
    }
};

int main() {
    vector<int> g = {1, 2, 3}, s = {1, 1};
    cout << Solution().findContentChildren(g, s);
}