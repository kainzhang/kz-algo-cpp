//
// Created by LOKKA on 2020/5/12.
//

#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e4 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> ch(130, 0);
    char S1[MAXN], S2[MAXN];
    cin.getline(S1, MAXN);
    cin.getline(S2, MAXN);
    int len = strlen(S2);
    for (int i = 0; i < len; i++) {
        ch[S2[i]]++;
    }
    len = strlen(S1);
    for (int i = 0; i < len; i++) {
        if (ch[S1[i]]) continue;
        else cout << S1[i];
    }
    cout << endl;
}