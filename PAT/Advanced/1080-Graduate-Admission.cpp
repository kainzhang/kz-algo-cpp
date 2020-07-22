//
// Created by LOKKA on 2020/7/22.
//

#include <bits/stdc++.h>
using namespace std;

struct Applicant {
    int idx, GE, GI, cho[6];
};

bool cmp1(const Applicant &a, const Applicant &b) {
    if (a.GE + a.GI == b.GE + b.GI)
        return a.GE > b.GE;
    return a.GE + a.GI > b.GE + b.GI;
}

bool cmp2(const Applicant &a, const Applicant &b) {
    return a.idx < b.idx;
}

vector<Applicant> vec(4e4 + 5), res[105];
vector<int> quo(105);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M, K;  // applicant, school, choice
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> quo[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> vec[i].GE >> vec[i].GI;
        vec[i].idx = i;
        for (int j = 0; j < K; j++) {
            cin >> vec[i].cho[j];
        }
    }
    sort(vec.begin(), vec.begin() + N, cmp1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            int bias = vec[i].cho[j];
            if (res[bias].size() < quo[bias]) {
                res[bias].push_back(vec[i]);
                break;
            } else {
                Applicant last = res[bias][res[bias].size() - 1];
                if (last.GI == vec[i].GI && last.GE == vec[i].GE) {
                    res[bias].push_back(vec[i]);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < M; i++) {
        int len = res[i].size();
        sort(res[i].begin(), res[i].end(), cmp2);
        for (int j = 0; j < len; j++) {
            if (j) cout << " ";
            cout << res[i][j].idx;
        }
        cout << endl;
    }
}