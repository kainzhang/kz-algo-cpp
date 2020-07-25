//
// Created by LOKKA on 2020/7/4.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 2005;

struct stu {
    string id;
    int C, M, E, A;  // 各项分数
    int CR, MR, ER, AR;  // 各项排名
};

vector<stu> s(mxN);
unordered_map<string, int> mp;

char sign;
bool cmp(const stu& a, const stu& b) {
    switch(sign) {
        case 'C': return a.C > b.C;
        case 'M': return a.M > b.M;
        case 'E': return a.E > b.E;
        default: return a.A > b.A;
    }
}

void print_res(int idx) {
    char sbj = 'A';
    int ranc = s[idx].AR;
    if (s[idx].CR < ranc) {
        sbj = 'C', ranc = s[idx].CR;
    }
    if (s[idx].MR < ranc) {
        sbj = 'M', ranc = s[idx].MR;
    }
    if (s[idx].ER < ranc) {
        sbj = 'E', ranc = s[idx].ER;
    }
    cout << ranc << " " << sbj << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> s[i].id >> s[i].C >> s[i].M >> s[i].E;
        s[i].A =  s[i].C + s[i].M + s[i].E;
    }

    sign = 'C';
    sort(s.begin() + 1, s.end(), cmp);
    for (int i = 1; i <= N; i++) {
        s[i].CR = (s[i].C == s[i - 1].C) ? s[i - 1].CR : i;
    }

    sign = 'M';
    sort(s.begin() + 1, s.end(), cmp);
    for (int i = 1; i <= N; i++) {
        s[i].MR = (s[i].M == s[i - 1].M) ? s[i - 1].MR : i;
    }

    sign = 'E';
    sort(s.begin() + 1, s.end(), cmp);
    for (int i = 1; i <= N; i++) {
        s[i].ER = (s[i].E == s[i - 1].E) ? s[i - 1].ER : i;
    }

    sign = 'A';
    sort(s.begin() + 1, s.end(), cmp);
    for (int i = 1; i <= N; i++) {
        s[i].AR = (s[i].A == s[i - 1].A) ? s[i - 1].AR : i;
        mp[s[i].id] = i;
    }

    for (int i = 0; i < M; i++) {
        string sid;
        cin >> sid;
        if (mp[sid]) {
            print_res(mp[sid]);
        } else {
            cout << "N/A" << endl;
        }
    }
}
