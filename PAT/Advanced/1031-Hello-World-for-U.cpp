//
// Created by LOKKA on 2020/4/22.
//

#include <iostream>

using namespace std;

int main() {
    string str;
    cin >> str;
    int len = str.size();
    int n1 = (len + 2) / 3;
    int n2 = len + 2 - n1 * 2;
    int i = 0;
    for (; i < n1 - 1; i++) {
        string line(n2, ' ');
        line[0] = str[i];
        line[n2 - 1] = str[len - i - 1];
        cout << line << endl;
    }
    int end = i + n2;
    for (; i < end; i++)
        cout << str[i];
    cout << endl;
}