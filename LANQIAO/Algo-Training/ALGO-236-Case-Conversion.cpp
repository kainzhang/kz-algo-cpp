//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
        str[i] = isupper(str[i]) ? tolower(str[i]) : toupper(str[i]);
    cout << str << endl;
}