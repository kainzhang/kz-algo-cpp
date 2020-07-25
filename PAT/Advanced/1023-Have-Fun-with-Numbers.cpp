//
// Created by LOKKA on 2020/4/22.
//

#include <iostream>
#include <cstring>

using namespace std;
int a[10];

int main() {
    char str[25];
    scanf("%s", str + 1);
    int len = strlen(str + 1);  // 加一位用于进位
    int tmp = 0;
    for (int i = len; i > 0; i--) {
        a[str[i] - '0']++;
        int t = (str[i] - '0') * 2 + tmp;
        str[i] = t % 10 + '0';
        a[t % 10]--;
        tmp = t / 10;
    }
    if (tmp) {  // 最终有进位
        str[0] = tmp + '0';
        a[tmp]--;
    }
    bool flag = true;
    for (int i = 0; i < 10; i++) {
        if (a[i] != 0) {
            flag = false;
            break;
        }
    }
    cout << (flag ? "Yes" : "No") << endl;
    cout << (tmp ? str : str + 1) << endl;
}