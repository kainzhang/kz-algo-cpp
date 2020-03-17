//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>

using namespace std;

int main() {
    int v1, v2, t, s, l, t2, ts = 0, s1 = 0, s2 = 0;
    cin >> v1 >> v2 >> t >> s >> l;
    t2 = l / v2;
    bool stop = false;
    for (int i = 0; i < t2; i++) {

        if (!stop) s1 += v1;
        s2 += v2;
        if (s1 - s2 >= t && !stop) {
            stop = true;
            ts = i;
        }
        if (i - ts == s && stop) stop = false;

        if (s1 >= l && i == t2 - 1) {
            cout << 'D' << endl;
            cout << t2 << endl;
            return 0;
        } else if (s1 >= l && i < t2 - 1) {
            cout << 'R' << endl;
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << 'T' << endl;
    cout << t2 << endl;
}