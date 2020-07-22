//
// Created by LOKKA on 2020/7/22.
//

#include <bits/stdc++.h>
using namespace std;

struct Result {
    int friendC, friendD; // A -> C, C -> D, D -> B
};

bool cmp(const Result &a, const Result &b) {
    return (a.friendC == b.friendC ? a.friendD < b.friendD : a.friendC < b.friendC);
}

unordered_map<string, vector<string> > mp;  // friends of same gender
unordered_map<int, bool> isF;  // all friend relations

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;  // people, relation
    cin >> N >> M;
    string fst, sec;
    for (int i = 0; i < M; i++) {
        cin >> fst >> sec;
        int f = abs(stoi(fst));
        int s = abs(stoi(sec));
        isF[f * 10000 + s] = isF[s * 10000 + f] = true;
        if (fst.size() == sec.size()) {
            mp[fst].push_back(sec);
            mp[sec].push_back(fst);
        }
    }
    int K;
    cin >> K;
    string A, B;
    for (int i = 0; i < K; i++) {
        vector<Result> res;
        cin >> A >> B;
        int b = abs(stoi(B));
        for (string &j : mp[A]) {  // A's friend C
            if (j == B) continue;
            for (string &k : mp[B]) {  // B's friend D
                if (k == A) continue;
                if (isF[abs(stoi(j)) * 10000 + abs(stoi(k))]) {
                    res.push_back(Result{abs(stoi(j)), abs(stoi(k))});
                }
            }
        }
        int len = res.size();
        printf("%d\n", len);
        if (!len) continue;
        sort(res.begin(), res.end(), cmp);
        for (int j = 0; j < len; j++) {
            printf("%04d %04d\n", res[j].friendC, res[j].friendD);
        }
    }
}