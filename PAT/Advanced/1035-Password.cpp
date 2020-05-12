//
// Created by LOKKA on 2020/4/23.
//

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct account {
    char usr[11], pwd[11];
};

int main() {
    int N, M = 0;
    char t_usr[11], t_pwd[11];
    scanf("%d", &N);
    vector<account> a;
    for (int i = 0; i < N; i++) {
        account t_a;
        scanf("%s %s", t_a.usr, t_a.pwd);
        int len = strlen(t_a.pwd), flag = 0;
        for (int j = 0; j < len; j++) {
            if (t_a.pwd[j] == '1') {
                t_a.pwd[j] = '@';
                flag++;
            } else if (t_a.pwd[j] == '0') {
                t_a.pwd[j] = '%';
                flag++;
            } else if (t_a.pwd[j] == 'l') {
                t_a.pwd[j] = 'L';
                flag++;
            } else if (t_a.pwd[j] == 'O') {
                t_a.pwd[j] = 'o';
                flag++;
            }
        }
        if (flag) a.push_back(t_a);
    }
    if (!a.size()) {
        if (N == 1) {
            cout << "There is " << N << " account and no account is modified" << endl;
        } else {
            cout << "There are " << N << " accounts and no account is modified" << endl;
        }
    } else {
        int len = a.size();
        cout << len << endl;
        for (int i = 0; i < len; i++) {
            cout << a[i].usr << " " << a[i].pwd << endl;
        }
    }
}