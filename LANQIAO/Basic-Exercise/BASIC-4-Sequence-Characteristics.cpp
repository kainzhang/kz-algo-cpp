//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    long long n, t, iMax = -99999, iMin = 99999, iSum = 0;
    cin >> n;
    while (n--) {
        cin >> t;
        iMax = t > iMax ? t : iMax;
        iMin = t < iMin ? t : iMin;
        iSum += t;
    }
    cout << iMax << endl;
    cout << iMin << endl;
    cout << iSum << endl;
}