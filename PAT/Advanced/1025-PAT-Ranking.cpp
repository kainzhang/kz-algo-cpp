//
// Created by LOKKA on 2020/7/5.
//

#include <bits/stdc++.h>
using namespace std;

struct tst {
    string id;
    int score, fin_rank, loc_num, loc_rank;
    bool operator < (const tst &t) const {
        if (score == t.score) {
            return id < t.id;
        }
        return score > t.score;
    }
};

vector<tst> tt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K, b = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            tst t;
            cin >> t.id >> t.score;
            t.loc_num = i;
            tt.push_back(t);
        }
        sort(tt.begin() + b, tt.begin() + b + K);
        for (int j = b, idx = 1; j < b + K; j++, idx++) {
            if (j > b && tt[j].score == tt[j - 1].score) {
                tt[j].loc_rank = tt[j - 1].loc_rank;
            } else {
                tt[j].loc_rank = idx;
            }
        }
        b += K;
    }
    sort(tt.begin(), tt.end());
    int len = tt.size();
    cout << len << endl;
    for (int i = 0; i < len; i++) {
        if (i > 0 && tt[i].score == tt[i - 1].score) {
            tt[i].fin_rank = tt[i - 1].fin_rank;
        } else {
            tt[i].fin_rank = i + 1;
        }
        cout << tt[i].id << " " << tt[i].fin_rank << " " << tt[i].loc_num << " " << tt[i].loc_rank << endl;
    }
}
