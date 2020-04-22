//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <string>

using namespace std;

string transEight(string a) {
    string tempStr = "";
    for (int i = 0; i < a.size(); i++) {
        switch (a[i]) {
            case '0':
                tempStr += "0000";
                break;
            case '1':
                tempStr += "0001";
                break;
            case '2':
                tempStr += "0010";
                break;
            case '3':
                tempStr += "0011";
                break;
            case '4':
                tempStr += "0100";
                break;
            case '5':
                tempStr += "0101";
                break;
            case '6':
                tempStr += "0110";
                break;
            case '7':
                tempStr += "0111";
                break;
            case '8':
                tempStr += "1000";
                break;
            case '9':
                tempStr += "1001";
                break;
            case 'A':
                tempStr += "1010";
                break;
            case 'B':
                tempStr += "1011";
                break;
            case 'C':
                tempStr += "1100";
                break;
            case 'D':
                tempStr += "1101";
                break;
            case 'E':
                tempStr += "1110";
                break;
            case 'F':
                tempStr += "1111";
                break;
            default:
                break;
        }
    }
    return tempStr;
}

int main() {
    int n = 0;
    cin >> n;
    string str, twoStr, eightStr;
    while (n--) {
        cin >> str;
        eightStr = "";
        twoStr = transEight(str);
        int twoLen = twoStr.size();
        if (twoLen % 3 == 1) {
            twoStr = "00" + twoStr;
            twoLen += 2;
        } else if (twoLen % 3 == 2) {
            twoStr = "0" + twoStr;
            twoLen++;
        }
        for (int i = 0; i < twoLen; i += 3) {
            int d = 4 * (twoStr[i] - '0') + 2 * (twoStr[i + 1] - '0') + (twoStr[i + 2] - '0');
            eightStr += (d + '0');
        }
        int j = 0;
        while (eightStr[j] == '0')j++;
        for (j; j < eightStr.size(); j++)
            cout << eightStr[j];
        cout << endl;
    }
}