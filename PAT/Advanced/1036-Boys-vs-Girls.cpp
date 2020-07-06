//
// Created by LOKKA on 2020/7/6.
//

#include <bits/stdc++.h>
using namespace std;

struct stu {
    string name, id;
    int grade;
    bool operator < (const stu &x) const {
        return grade < x.grade;
    }
};

vector<stu> M, F;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--) {
        stu tmp;
        char gender;
        cin >> tmp.name >> gender >> tmp.id >> tmp.grade;
        if (gender == 'M') {
            M.push_back(tmp);
        } else {
            F.push_back(tmp);
        }
    }
    sort(M.begin(), M.end());
    sort(F.begin(), F.end());
    int iF = F.size(), iM = M.size(), ok = 1;
    if (!iF) {
        cout << "Absent" << endl;
        ok = 0;
    } else {
        cout << F[iF - 1].name << " " << F[iF - 1].id << endl;
    }
    if (!iM) {
        cout << "Absent" << endl;
        ok = 0;
    } else {
        cout << M[0].name << " " << M[0].id << endl;
    }
    if (ok) {
        cout << F[iF - 1].grade - M[0].grade << endl;
    } else {
        cout << "NA" << endl;
    }
}
