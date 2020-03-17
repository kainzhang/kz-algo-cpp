//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    string str;
    cin >> str;
    long long sum = 0, t = 0;
    for (int i = str.size() - 1; i >= 0; i--) {
        if (isdigit(str[i])) {
            sum += (str[i] - '0') * pow(16, t);
        } else {
            sum += (str[i] - 'A' + 10) * pow(16, t);
        }
        t++;
    }
    cout << sum << endl;
}