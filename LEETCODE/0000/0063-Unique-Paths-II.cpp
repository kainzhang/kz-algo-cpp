//
// Created by LOKKA on 2020/4/6.
//

#include <iostream>
#include <vector>

using namespace std;

long long dp[105][105];

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    if (obstacleGrid[0][0] == 1)  //起点有障碍，直接返回 0
        return 0;
    dp[0][0] = 1;   // 路径数初始为 1
    int row = obstacleGrid.size(), col = obstacleGrid[0].size();
    for (int i = 1; i < col; i++) {  //从起点开始更新第一行路径数
        dp[0][i] = (obstacleGrid[0][i] == 0 && dp[0][i - 1] == 1) ? 1 : 0;
    }
    for (int j = 1; j < row; j++) {  //从起点开始更新第一列路径数
        dp[j][0] = (obstacleGrid[j][0] == 0 && dp[j - 1][0] == 1) ? 1 : 0;
    }
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[row - 1][col - 1];
}

int main() {
    vector<vector<int>> obstacleGrid = {
            {0, 0, 0},
            {0, 1, 0},
            {0, 0, 0}
    };
//    vector<vector<int>> obstacleGrid = {
//            {0, 0}
//    };
    cout << uniquePathsWithObstacles(obstacleGrid) << endl;
}