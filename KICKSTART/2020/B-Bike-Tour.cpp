//
// Created by LOKKA on 2020/4/20.
//

#include <iostream>

using namespace std;

int main() {
    int T, N;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        int H[105], ans = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &H[i]);
        }
        for (int i = 1; i < N - 1; i++) {
            if (H[i] > H[i - 1] && H[i] > H[i + 1])
                ans++;
        }
        printf("Case #%d: %d\n", t, ans);
    }
}