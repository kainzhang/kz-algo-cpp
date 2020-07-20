//
// Created by LOKKA on 2020/7/19.
//

#include <bits/stdc++.h>
using namespace std;

int N, K, P, max_sum, flag = 0;
vector<int> v, tmp_res, res;

void dfs(int idx, int sum, int fac_sum, int cnt) {
    if (sum == N) {
        if (fac_sum > max_sum && cnt == K) {
            max_sum = fac_sum;
            res = tmp_res;
        }
        return;
    }
    for (int i = idx; i > 0; i--) {
        if (sum + v[i] <= N && cnt + 1 <= K) {
            tmp_res.push_back(i);
            dfs(i, sum + v[i], fac_sum + i, cnt + 1);
            tmp_res.pop_back();
        }
    }
}

int main() {
    scanf("%d %d %d", &N, &K, &P);
    for (int i = 0; pow(i, P) <= N; i++) {
        v.push_back(pow(i, P));
    }
    dfs(v.size() - 1, 0, 0, 0);
    if (res.size() != K) {
        printf("Impossible\n");
        return 0;
    }
    printf("%d = %d^%d", N, res[0], P);
    int len = res.size();
    for (int i = 1; i < len; i++) {
        printf(" + %d^%d", res[i], P);
    }
}
