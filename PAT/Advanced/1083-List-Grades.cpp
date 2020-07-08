//
// Created by LOKKA on 2020/7/8.
//

#include <bits/stdc++.h>
using namespace std;

struct stu {
    string name, id;
    int grade;
    bool operator < (const stu &x) const {
        return grade > x.grade;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<stu> vec(N);
    for (int i = 0; i < N; i++) {
        cin >> vec[i].name >> vec[i].id >> vec[i].grade;
    }
    int grade1, grade2;
    cin >> grade1 >> grade2;
    vector<stu> res;
    for (auto &i : vec) {
        if (i.grade >= grade1 && i.grade <= grade2) {
            res.push_back(i);
        }
    }
    if (!res.size()) {
        cout << "NONE" << endl;
        return 0;
    }
    sort(res.begin(), res.end());
    for (auto &i : res) {
        cout << i.name << " " << i.id << endl;
    }
}
