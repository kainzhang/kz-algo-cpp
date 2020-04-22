//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 70;
int n, l, arr[N], vis[N];
bool ok;
void dfs(int cur, int len, int used) {
    if (ok) return;
    if (len == l) {
        if (used == n) {
            ok = true;
        } else {
            dfs(0, 0, used);
        }
        return;
    }
    if (!len) {
        int j = 0;
        while(vis[j]) j++;
        vis[j]++;
        dfs(j+1, arr[j], used+1);
        vis[j] = 0;
    } else {
        for (int i=cur; i<n; i++) {
            if (!vis[i] && len + arr[i] <= l) {
                if(arr[i] == arr[i-1] && !vis[i-1])
                    continue;
                vis[i] = 1;
                dfs(i+1, len+arr[i], used+1);
                vis[i] = 0;
                if (arr[i] + len == l) return;
            }
        }
    }
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    while(scanf("%d", &n) && n) {
        int sum = 0, ans;
        ok = false;
        for(int i=0; i<n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        sort(arr, arr + n, cmp);
        for(int i=arr[0]; i<=sum; i++) {
            if (sum % i == 0) {
                memset(vis, 0, sizeof(vis));
                l = i;
                dfs(0, 0, 0);
                if (ok) {
                    ans = i;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}
