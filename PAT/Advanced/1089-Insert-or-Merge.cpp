//
// Created by LOKKA on 2020/7/17.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) cin >> b[i];
    int i = 1;
    while (b[i] >= b[i - 1] && i < N) i++;
    int idx = i;
    while (b[i] == a[i] && i < N) i++;
    if (i == N) {
        cout << "Insertion Sort" << endl;
        sort(a.begin(), a.begin() + idx + 1);
    } else {
        cout << "Merge Sort" << endl;
        bool flag = true;
        int k = 1;
        while (flag) {
            flag = false;
            for (int j = 0; j < N; j++) {  // a, b 存在不同元素
                if (a[i] != b[i]) flag = true;
            }
            for (int j = 0; j < N; j += k * 2) {
                int r = j + k * 2;
                if (r > N) r = N;
                sort(a.begin() + j, a.begin() + r);
            }
            k *= 2;
        }
    }
    for (int j = 0; j < N; j++) {
        if (j) cout << " ";
        cout << a[j];
    }
}
