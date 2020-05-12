//
// Created by LOKKA on 2020/3/16.
//

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int i, j, len = 0, start = 0, end = 0;
        for (i = 2; i <= sqrt(n); i++) {
            int tmp = 1;
            for (j = i;; j++) {
                tmp *= j;
                if (n % tmp != 0)
                    break;
            }
            if (len < j - i) {
                len = j - i;
                start = i;
                end = j;
            }
        }
        if (!len)
            cout << "1" << endl << n;
        else
            cout << len << endl;
        for (int k = start; k < end; k++) {
            cout << k;
            if (k < end - 1) cout << "*";
        }
        cout << endl;
    }
}
