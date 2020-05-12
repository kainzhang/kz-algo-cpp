//
// Created by LOKKA on 2020/5/8.
//

#include <bits/stdc++.h>

using namespace std;

//struct Ses {
//    int sum, num, cnt;
//
//    bool operator < (const Ses& s) const {
//        return num < s.num;
//    }
//};
//
//int solve() {
//    int N, K;
//    cin >> N >> K;
//    vector<int> M(N);
//    priority_queue<Ses> que;
//    cin >> M[0];
//    for (int i = 1; i < N; i++) {
//        cin >> M[i];
//        que.push({M[i] - M[i - 1], M[i] - M[i - 1], 1});
//    }
//    while (K--) {
//        Ses tmp = que.top();
//        if (tmp.num == 1) break;
//        que.pop();
//        tmp.cnt++;
//        tmp.num = tmp.sum / tmp.cnt;
//        if (tmp.sum % tmp.cnt) tmp.num++;
//        que.push(tmp);
//    }
//    return que.top().num;
//}


int solve() {
    int N, K;
    cin >> N >> K;
    vector<int> M(N);
    for (int i = 0; i < N; i++) {
        cin >> M[i];
    }
    int lo = 1, hi = M[N - 1] - M[0];
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int sum = 0;
        for (int i = 1; i < N; i++) {
            int dis = M[i] - M[i - 1];
            sum += (dis + mid - 1) / mid - 1;
        }
        if (sum > K) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
}