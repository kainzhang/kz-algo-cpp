//
// Created by LOKKA on 2020/4/2.
//

#include <iostream>
#include <vector>

using namespace std;

void setZeroes_1(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size(), col_0 = 0;
    for (int i = 0; i < row; i++) {
        if (!matrix[i][0])
            col_0 = 1;
        for (int j = 1; j < col; j++) {
            if (!matrix[i][j]) {
                matrix[i][0] = matrix[0][j] = 0; //标记
            }
        }
    }
    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            if (!matrix[i][0] || !matrix[0][j])
                matrix[i][j] = 0;
        }
    }
    if (!matrix[0][0]) {    //第一行清零
        for (int i = 1; i < col; i++) {
            matrix[0][i] = 0;
        }
    }
    if (col_0) {            //第一列清零
        for (int i = 0; i < row; i++) {
            matrix[i][0] = 0;
        }
    }
}

void setZeroes_2(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = matrix[0].size();
    vector<int> r(row, 0), c(col, 0);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (!matrix[i][j]) {
                r[i] = c[j] = 1; //标记
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (r[i] || c[j])
                matrix[i][j] = 0;
        }
    }
}

int main() {
//    vector<vector<int>> mat = {
//            {1, 1, 1},
//            {1, 0, 1},
//            {1, 1, 1},
//    };
    vector<vector<int>> mat = {
            {0, 1, 2, 0},
            {3, 4, 5, 2},
            {1, 3, 1, 5},
    };

    //setZeroes_1(mat);
    setZeroes_2(mat);

    for (int i = 0; i < mat.size(); i++) {
        cout << "  [";
        for (int j = 0; j < mat[0].size(); j++) {
            if (j > 0)
                cout << ",";
            cout << mat[i][j];
        }
        cout << "]";
        if (i < mat.size() - 1)
            cout << ",";
        cout << endl;
    }
}
