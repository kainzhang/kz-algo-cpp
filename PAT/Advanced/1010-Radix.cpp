//
// Created by LOKKA on 2020/7/4.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 字符串转 10 进制
ll str_to_dec(string str, ll radix) {
    ll res = 0;
    int len = str.size();
    for (int i = 0; i < len; i++) {
        int tmp = (isdigit(str[i]) ? str[i] - '0' : str[i] - 'a' + 10);
        res += tmp * pow(radix, len - i - 1);
    }
    return res;
}

// 获取基数
ll get_radix(string str, ll num) {  // num 为已知数的 10 进制
    ll radix = 0;

    // 计算基数范围
    char maxC = *max_element(str.begin(), str.end()); // 找到最大字符
    ll lo = (isdigit(maxC) ? maxC - '0' : maxC - 'a' + 10) + 1;
    ll hi = max(lo, num);

    // 使用二分查找计算基数
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        ll tmp = str_to_dec(str, mid);
        if (tmp > num || tmp < 0) {  // 比已知数大或向上溢出
            hi = mid - 1;
        } else if (tmp < num) {  // 比已知数小
            lo = mid + 1;
        } else {
            radix = mid;
            break;
        }
    }
    return radix;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string N1, N2;
    int tag, radix;
    cin >> N1 >> N2 >> tag >> radix;
    ll num = (tag & 1) ? str_to_dec(N1, radix) : str_to_dec(N2, radix);
    ll ans = (tag & 1) ? get_radix(N2, num) : get_radix(N1, num);
    if (ans) {
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }
}
