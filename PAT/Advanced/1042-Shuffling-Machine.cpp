//
// Created by LOKKA on 2020/4/23.
//

#include <iostream>
#include <vector>

using namespace std;

char ch[] = {'S', 'H', 'C', 'D', 'J'};

int main() {
    int K, t;
    vector<int> od(55), cd(55), cd2(55);
    for (int i = 1; i < 55; i++)
        cd[i] = i - 1;

    scanf("%d", &K);
    for (int i = 1; i < 55; i++) {
        scanf("%d", &t);
        od[i] = t;
    }
    int cnt = 0;
    while (K--) {
        cnt++;
        if (cnt & 1) {
            for (int i = 1; i < 55; i++) {
                cd2[od[i]] = cd[i];
            }
        } else {
            for (int i = 1; i < 55; i++) {
                cd[od[i]] = cd2[i];
            }
        }
    }
    if (cnt & 1) {
        for (int i = 1; i < 54; i++)
            cout << ch[cd2[i] / 13] << cd2[i] % 13 + 1 << " ";
        cout << ch[cd2[54] / 13] << cd2[54] % 13 + 1 << endl;
    } else {
        for (int i = 1; i < 54; i++)
            cout << ch[cd[i] / 13] << cd[i] % 13 + 1 << " ";
        cout << ch[cd[54] / 13] << cd[54] % 13 + 1 << endl;
    }
}