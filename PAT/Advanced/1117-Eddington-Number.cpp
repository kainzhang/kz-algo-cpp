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
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < N; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    int i;
    for (i = 0; i < N; i++) {
        if (v[i] <= i + 1) break;
    }
    cout << i << endl;
}
