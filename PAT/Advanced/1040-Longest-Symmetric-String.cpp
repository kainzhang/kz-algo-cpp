//
// Created by LOKKA on 2020/7/10.
//

#include <bits/stdc++.h>
using namespace std;

int dp[1010][1010];

/**
 *  DP
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    getline(cin, str);

    int len = str.size(), ans = 1;
    for (int i = 0; i < len; i++) {
        dp[i][i] = 1;  // 1 位回文
        if (i < len - 1) {
            if (str[i] == str[i + 1]) {
                dp[i][i + 1] = 1;  // 2 位回文
                ans = 2;  // 更新最长长度
            }
        }
    }
    for (int L = 3; L <= len; L++) {  // 从 3 位字符串开始
        for (int i = 0; i + L - 1 < len; i++) {
            int j = i + L - 1;

            //  状态转移方程
            if (str[i] == str[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ans = L;  // 更新最长长度
            }
        }
    }
    cout << ans << endl;
}


/**
 *  Manacher
 */

//#include <bits/stdc++.h>
//using namespace std;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    string str, S = "$#";
//    getline(cin, str);
//    for (char c : str) {
//        S += c;
//        S += '#';
//    }
//    int mxL = 0, mxR = 0, idx = 0, len = S.size();
//    vector<int> p(len);
//    for (int i = 1; i < len; i++) {
//        p[i] = mxL < i ? 1 : min(mxL - i, p[idx * 2 - 1]);
//        while(S[i - p[i]] == S[i + p[i]]) {
//            p[i]++;
//        }
//        if (mxL < i + p[i]) {
//            mxL = i + p[i];
//            idx = i;
//        }
//        mxR = max(mxR, p[i]);
//    }
//    cout << mxR - 1 << endl;
//}