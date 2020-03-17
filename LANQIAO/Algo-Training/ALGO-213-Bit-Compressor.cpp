//
// Created by LOKKA on 2020/3/16.
//

#include <cstdio>
#include <cstring>

const int MAXN = 50;
int L, l, N;
char str[MAXN];
int ans;

void dfs(int i, int length, int num_1) {
    if (i > l) {  //结束条件
        if (length == L && num_1 == N)
            ans++;
        return;
    } else if (i == l) {  //最后一个位置
        dfs(i + 1, length + 1, num_1 + str[i] - '0');
        return;
    }
    if (length > L || num_1 > N || ans >= 2)
        return;
    if (str[i] == '0') {
        dfs(i + 1, length + 1, num_1);
        return;
    }

    // 以下为str[i]==1的情况
    if (str[i - 1] == '1')
        return;
    if (str[i + 1] == '0')
        dfs(i + 1, length + 1, num_1 + 1);
    if (str[i + 1] == '1' && str[i + 2] != '1')
        dfs(i + 2, length + 2, num_1 + 2);
    long long tmp = 0;
    for (int j = i; j <= l; j++) {
        tmp *= 2;
        tmp += str[j] - '0';
        if (tmp + num_1 > N || tmp + length > L)
            break;
        if (tmp > j - i + 1 && str[j + 1] != '1')
            dfs(j + 1, tmp + length, num_1 + tmp);
    }
}

int main() {
    while (~scanf("%d %d", &L, &N)) {
        scanf("%s", str + 1);
        l = strlen(str + 1);
        ans = 0;
        dfs(1, 0, 0);
        if (ans == 0)
            printf("NO\n");
        else if (ans == 1)
            printf("YES\n");
        else
            printf("NOT UNIQUE\n");
    }
}