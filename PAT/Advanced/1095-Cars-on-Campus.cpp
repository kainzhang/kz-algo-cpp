//
// Created by LOKKA on 2020/7/18.
//

#include <bits/stdc++.h>
using namespace std;

struct Record {
    string pn;
    int time;
    bool in;
};

bool cmp1(const Record &a, const Record &b) {
    return (a.pn == b.pn ? a.time < b.time : a.pn < b.pn);
}

bool cmp2(const Record &a, const Record &b) {
    return a.time < b.time;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    string plate, cmd;
    plate.resize(10);
    cmd.resize(5);
    int hh, mm, ss;
    vector<Record> v;
    Record c;
    for (int i = 0; i < N; i++) {
        scanf("%s %d:%d:%d %s", &plate[0], &hh, &mm, &ss, &cmd[0]);
        c.pn = plate;
        c.time = hh * 3600 + mm * 60 + ss;
        if (cmd[0] == 'i') c.in = true;
        else c.in = false;
        v.push_back(c);
    }
    sort(v.begin(), v.end(), cmp1);
    map<string, int> mp;
    int len = v.size(), mxDur = 0;
    vector<string> ans;
    vector<Record> r;
    for (int i = 0; i < len - 1; i++) {
        if (v[i].pn == v[i + 1].pn && v[i].in && !v[i + 1].in) {
            mp[v[i].pn] += v[i + 1].time - v[i].time;
            r.push_back(v[i]);
            r.push_back(v[i + 1]);
            if (mp[v[i].pn] > mxDur) {
                mxDur = mp[v[i].pn];
                ans.clear();
                ans.push_back(v[i].pn);
            } else if (mp[v[i].pn] == mxDur) {
                ans.push_back(v[i].pn);
            }
        }
    }

    sort(r.begin(), r.end(), cmp2);
    vector<int> cnt(N);
    len = r.size();
    for (int i = 0; i < len; i++) {
        if (i == 0) cnt[i] += (r[i].in ? 1 : -1);
        else cnt[i] = cnt[i - 1] + (r[i].in ? 1 : -1);
    }
    int tmp = 0, j;
    for (int i = 0; i < K; i++) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh * 3600 + mm * 60 + ss;
        for (j = tmp; j < len; j ++) {
            if (r[j].time > time) {
                printf("%d\n", cnt[j - 1]);
                break;
            } else if (j == len - 1) {
                printf("%d\n", cnt[j]);
            }
        }
        tmp = j;
    }
    len = ans.size();
    sort(ans.begin(), ans.end());
    for (int i = 0; i < len; i++) {
        printf("%s ", ans[i].c_str());
    }
    printf("%02d:%02d:%02d", mxDur / 3600, mxDur % 3600 / 60, mxDur % 60);
}
