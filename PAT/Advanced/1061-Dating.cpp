//
// Created by LOKKA on 2020/5/14.
//

#include <bits/stdc++.h>
using namespace std;

string W[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    string str[4];
    for (int i = 0; i < 4; i++)
        cin >> str[i];

    int DAY, HH, MM, cnt = 0;

    int len = min(str[0].size(), str[1].size());
    for (int i = 0; i < len; i++) {
        if (str[0][i] == str[1][i]) {
            if (isupper(str[0][i]) && str[0][i] <= 'N') {
                if(!cnt) {
                    DAY = str[0][i] - 'A';
                    cnt++;
                } else {
                    HH = str[0][i] - 'A' + 10;
                    break;
                }
            } else if (isdigit(str[0][i]) && cnt) {
                HH = str[0][i] - '0';
                break;
            }
        }
    }

    len = min(str[2].size(), str[3].size());
    for (int i = 0; i < len; i++) {
        if (isalpha(str[2][i]) && str[2][i] == str[3][i]) {
            MM = i;
            break;
        }
    }
    cout << W[DAY] << " ";
    printf("%02d:%02d\n", HH, MM);
}