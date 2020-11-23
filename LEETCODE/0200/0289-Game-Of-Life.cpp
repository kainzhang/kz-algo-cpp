//
// Created by LOKKA on 2020/4/2.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


void gameOfLife(vector<vector<int>>& board) {
    int d[] = {-1, 0, 1};
    int row = board.size(), col = board[0].size();

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int cnt = 0;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (!d[x] && !d[y]) continue;
                    int r = i + d[x], c = j + d[y];
                    if (0 <= r && r < row && 0 <= c && c < col && abs(board[r][c]) == 1)
                        cnt ++;
                }
            }
            if (board[i][j] == 1 && (cnt < 2 || cnt > 3))
                board[i][j] = -1;
            else if (board[i][j] == 0 && cnt == 3)
                board[i][j] = 2;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            board[i][j] = board[i][j] > 0 ? 1 : 0;
        }
    }
}

int main() {
    vector<vector<int>> board = {
            {0, 1, 0},
            {0, 0, 1},
            {1, 1, 1},
            {0, 0, 0}
    };

    gameOfLife(board);

    for (int i = 0; i < board.size(); i++) {
        cout << "  [";
        for (int j = 0; j < board[0].size(); j++) {
            if (j > 0)
                cout << ",";
            cout << board[i][j];
        }
        cout << "]";
        if (i < board.size() - 1)
            cout << ",";
        cout << endl;
    }
}