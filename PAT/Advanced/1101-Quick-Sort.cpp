//
// Created by LOKKA on 2020/7/10.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    int mxI = -1;
    for (int i = 0; i < N; i++) {
        mxI = max(mxI, b[i]);
        if (a[i] == b[i] && b[i] == mxI) {
            ans.push_back(a[i]);
        }
    }
    int len = ans.size();
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}
