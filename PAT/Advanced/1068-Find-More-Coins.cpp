//
// Created by LOKKA on 2020/7/18.
//

#include <bits/stdc++.h>
using namespace std;

int slt[10005][105];

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> v(N + 1), dp(M + 1);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < N; i++) {
        for (int j = M; j >= v[i]; j--) {
            if (dp[j - v[i]] + v[i] >= dp[j]) {  //  必须大于等于
                slt[i][j] = 1;
                dp[j] = dp[j - v[i]] + v[i];
            }
        }
    }
    if (dp[M] != M) {  // 必须恰好为 M
        printf("No Solution");
    } else {
        int i = N, flag = 0;
        while (M) {
            if (slt[i][M] == 1) {
                if (flag) printf(" ");
                printf("%d", v[i]);
                flag++;
                M -= v[i];
            }
            i--;
        }
    }

}
