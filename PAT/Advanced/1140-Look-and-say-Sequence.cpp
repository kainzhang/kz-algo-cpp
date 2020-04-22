//
// Created by LOKKA on 2020/4/21.
//

#include <iostream>

using namespace std;

int main() {
    string str;
    int N;
    cin >> str >> N;
    for (int i = 1; i < N; i++) {
        string tmp;
        int cnt = 1, len = str.length();
        for (int j = 1; j <= len; j++) {
            if (str[j] == str[j - 1]) {
                cnt++;
            } else {
                tmp += str[j - 1] + to_string(cnt);
                cnt = 1;
            }
        }
        str = tmp;
    }
    cout << str << endl;
}