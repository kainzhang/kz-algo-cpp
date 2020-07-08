//
// Created by LOKKA on 2020/7/8.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, mx = -1;
    cin >> N;
    vector<int> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    double sum = vec[0];
    for (int i = 1; i < N; i++) {
        sum = (sum + vec[i]) / 2;
    }
    cout << floor(sum) << endl;
}
