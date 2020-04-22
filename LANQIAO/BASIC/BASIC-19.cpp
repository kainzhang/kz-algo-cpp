//
// Created by LOKKA on 2020/4/4.
// 完美的代价

#include <iostream>

using namespace std;

char str[8005];

int main() {
    int n, flag = 0, cnt = 0;
    scanf("%d %s", &n, str);
    int t = n - 1;
    for (int i = 0; i < t; i++) {
        for (int j = t; j >= i; j--) {
            if (j == i) {
                if (flag++ || n % 2 == 0) {
                    cout << "Impossible" << endl;
                    return 0;
                }
                cnt += n / 2 - i;
            } else if (str[j] == str[i]) {
                for (int k = j; k < t; k++) {
                    swap(str[k], str[k + 1]);
                    cnt++;
                }
                t--;
                break;
            }
        }
    }
    cout << cnt << endl;
}