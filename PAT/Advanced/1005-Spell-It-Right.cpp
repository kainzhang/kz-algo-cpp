//
// Created by LOKKA on 2020/4/17.
//

#include <iostream>
#include <cstring>

using namespace std;

string ch[] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"
};

bool flag;

void printAns(int n) {
    int t = n % 10;
    n /= 10;
    if (n) printAns(n);
    if (flag) cout << " ";
    cout << ch[t];
    flag = true;
}

int main() {
    char str[105];
    while (scanf("%s", str) != EOF) {
        flag = false;
        int len = strlen(str), sum = 0;
        for (int i = 0; i < len; i++)
            sum += str[i] - '0';
        printAns(sum);
        cout << endl;
    }
}