//
// Created by LOKKA on 2020/3/27.
//

/*
 * 一个机器人只能向下和向右移动每次只能移动一步，
 * 设计算法求它从（1，1）移动到（m，n）有多少条路径。
 */

#include <iostream>

using namespace std;

int dp[105][105];  //记忆化搜索

int uniquePaths(int m, int n)  {
    if (m < 0 || n < 0) return 0;   //越界，返回0
    if (dp[m][n]) return dp[m][n];  //直接返回计算过的值
    return dp[m][n] = (m == 0 || n == 0) ? 1 : uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
}   // m 或 n 为 0 时，到达边界。由于边界的路径数全部为 1，返回 1。否则继续分解问题

int main() {
    int m, n;
    cin >> m >> n;
    cout << uniquePaths(m, n) << endl;
}