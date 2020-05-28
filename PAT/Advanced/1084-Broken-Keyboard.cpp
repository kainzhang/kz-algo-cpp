//
// Created by LOKKA on 2020/5/26.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    string in, out;
    cin >> in >> out;
    int len = in.size();
    map<char, int> mp;
    for (int i = 0, j = 0; i < len; i++) {
        in[i] = toupper(in[i]);
        out[j] = toupper(out[j]);
        if (in[i] == out[j])
            j++;
        else {
            if (mp.count(in[i]))
                continue;
            printf("%c", in[i]);
            mp[in[i]]++;
        }
    }
}