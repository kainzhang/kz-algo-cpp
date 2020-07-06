//
// Created by LOKKA on 2020/7/5.
//

#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string str) {
    int len = str.size();
    int mid = len / 2 + 1;
    for (int i = 0; i <= mid; i++) {
        if (str[i] != str[len - i - 1])
            return false;
    }
    return true;
}

string get_sum(string str) {
    string res = str;
    int len = str.size(), tmp = 0;
    for (int i = len - 1; i >= 0; i--) {
        tmp += res[i] - '0' + str[len - i - 1] - '0';
        res[i] = tmp % 10 + '0';
        tmp /= 10;
    }
    if (tmp) {
        res = "1" + res;
    }
    return res;
}

int main() {
    string N;
    int K, i;
    cin >> N >> K;
    for (i = 0; i < K; i++) {
        if (is_palindrome(N)) {
            break;
        }
        N = get_sum(N);
    }
    cout << N << endl << i << endl;
}