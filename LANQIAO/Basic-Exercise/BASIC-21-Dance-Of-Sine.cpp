//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;
int n;

string getAn(int nn, int a, int i) {
    int flag = -1;
    a *= flag;
    string sym, temp;
    switch (a) {
        case 1:
            sym = "+";
            break;
        case -1:
            sym = "-";
            break;
    }
    stringstream ss;

    if (i == nn) {
        ss << nn;
        string str = ss.str();
        return "sin(" + str + ")";
    } else {
        ss << i;
        string str = ss.str();
        return "sin(" + str + sym + getAn(nn, a, ++i) + ")";
    }
}

string getSn(int nn) {
    stringstream ss;
    if (nn == 1) {
        ss << n - nn + 1;
        string str = ss.str();
        return getAn(nn, 1, 1) + "+" + str;
    } else {
        ss << n - nn + 1;
        string str = ss.str();
        return "(" + getSn(nn--) + ")" + getAn(nn--, 1, 1) + "+" + str;
    }

}

int main() {
    cin >> n;
    cout << getSn(n);
}