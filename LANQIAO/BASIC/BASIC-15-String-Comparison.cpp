//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    if (str1.length() != str2.length()) {
        cout << '1' << endl;
    } else if (str1 == str2) {
        cout << '2' << endl;
    } else {
        for (int i = 0; i < str1.length(); i++) {
            str1[i] = toupper(str1[i]);
            str2[i] = toupper(str2[i]);
        }
        if (str1 == str2) cout << '3' << endl;
        else cout << '4' << endl;
    }
}