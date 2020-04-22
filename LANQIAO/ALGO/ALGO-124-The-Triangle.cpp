//
// Created by LOKKA on 2020/3/22.
// 数字三角形

#include <iostream>

using namespace std;

struct node {
    int data, next_y;
};

int max_sum(int **a, node **ans, int n) {
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++) {
            if (a[i + 1][j] > a[i + 1][j + 1]) {
                ans[i][j].next_y = j;
                a[i][j] += a[i + 1][j];
            } else {
                ans[i][j].next_y = j + 1;
                a[i][j] += a[i + 1][j + 1];
            }
        }

    return a[0][0];
}

void print_ans(node **ans, int n) {
    for (int i = 0, j = 0; i < n; i++) {
        cout << ans[i][j].data << " ";
        j = ans[i][j].next_y;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int **a = new int *[n];
    node **ans = new node *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[i + 1];
        ans[i] = new node[i + 1];
        for (int j = 0; j <= i; j++) {
            scanf("%d", &a[i][j]);
            ans[i][j].data = a[i][j];
        }
    }
    cout << max_sum(a, ans, n) << endl;
    //print_ans(ans, n);
}


