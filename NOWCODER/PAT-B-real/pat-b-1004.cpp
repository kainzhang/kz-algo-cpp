//
// Created by LOKKA on 2020/3/16.
// 1004福尔摩斯的约会

#include <iostream>
#include <cctype>

using namespace std;

int main() {
    string str1, str2, str3, str4;
    cin >> str1 >> str2 >> str3 >> str4;
    int len = str1.length() < str2.length() ? str1.length() : str2.length();
    int cnt = 0;
    for (int i = 0; i < len; i++) {
        if (str1[i] == str2[i] && isupper(str1[i]) && !cnt) {
            string ans1;
            switch (str1[i]) {
                case 'A':
                    ans1 = "MON";
                    break;
                case 'B':
                    ans1 = "TUE";
                    break;
                case 'C':
                    ans1 = "WED";
                    break;
                case 'D':
                    ans1 = "THU";
                    break;
                case 'E':
                    ans1 = "FRI";
                    break;
                case 'F':
                    ans1 = "SAT";
                    break;
                case 'G':
                    ans1 = "SUN";
                    break;
            }
            cout << ans1 << " ";
            cnt++;
            continue;
        }
        if (str1[i] == str2[i] && (isupper(str1[i]) || isdigit(str1[i])) && cnt) {
            if (str1[i] >= '0' && str1[i] <= '9')
                printf("%02d:", str1[i] - '0');
            else
                printf("%d:", str1[i] - 'A' + 10);
            break;
        }
    }
    len = str3.length() < str4.length() ? str3.length() : str4.length();
    for (int i = 0; i < len; i++) {
        if (str3[i] == str4[i] && islower(str3[i])) {
            printf("%02d\n", i);
            break;
        }
    }
}
