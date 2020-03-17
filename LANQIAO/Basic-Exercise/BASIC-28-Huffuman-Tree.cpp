//
// Created by LOKKA on 2020/3/17.
//

#include<iostream>
#include<string.h>

using namespace std;

int main() {
    int n, t, a[100005], sum = 0;
    memset(a, 0, sizeof(a));
    cin >> n;
    while (n--) {
        cin >> t;
        a[t]++;
    }
    t = 0;
    for (int i = 1; i < 100005;) {
        if (t && a[i]) {
            a[i + t]++;
            a[i]--;
            sum += i + t;
            t = 0;
            goto aaa;
        }

        if (a[i] >= 2) {
            a[i * 2] += a[i] / 2;
            sum += i * 2 * (a[i] / 2);
            a[i] %= 2;
            t = 0;
        } else if (a[i]) {
            t = i;
            a[i] = 0;
        }
        aaa:
        if (!a[i])i++;
    }
    cout << sum << endl;
}