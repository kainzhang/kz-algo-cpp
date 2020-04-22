//
// Created by LOKKA on 2020/4/20.
//

#include <iostream>
#include <algorithm>

using namespace std;
int N, arr[1005], cbt[1005], idx = 0;

void getInorder(int root) {
    if (root > N) return;
    getInorder(root * 2);     // 左孩儿
    cbt[root] = arr[idx++];
    getInorder(root * 2 + 1); // 右孩儿
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + N);
    getInorder(1);
    for (int i = 1; i <= N; i++) {
        if (i > 1) putchar(32);
        printf("%d", cbt[i]);
    }
}