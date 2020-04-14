//
// Created by LOKKA on 2020/4/6.
// dfs, backtrace

#include <iostream>
#include <vector>

using namespace std;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int sx, sy, fx, fy, row, col, res = 0;

void dfs(int x, int y, int blk, vector<vector<int>> &grid) {
    blk--;
    if (blk < 0) return;
    if (x == fx && y == fy && !blk) {
        res++;
        return;
    }
    grid[x][y] = -1;    // 要求每个无障碍方块都要通过一次
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= row || ny < 0 || ny >= col || grid[nx][ny] == -1)
            continue;
        dfs(nx, ny, blk, grid);
    }
    grid[x][y] = 0;
}

int uniquePathsIII(vector<vector<int>> &grid) {
    int blk = 0;
    row = grid.size(), col = grid[0].size();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] != -1)   //记录可经过的点的数量
                blk++;
            if (grid[i][j] == 1) {
                sx = i;
                sy = j;
            } else if (grid[i][j] == 2) {
                fx = i;
                fy = j;
            }
        }
    }
    dfs(sx, sy, blk, grid);
    return res;
}

int main() {
    vector<vector<int>> grid = {
            {1, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 2}
    };
//    vector<vector<int>> grid = {
//            {1, 0, 0, 0},
//            {0, 0, 0, 0},
//            {0, 0, 2, -1}
//    };
//    vector<vector<int>> grid = {
//            {0, 1},
//            {2, 0}
//    };
    cout << uniquePathsIII(grid) << endl;
}