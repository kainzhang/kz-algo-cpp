//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <stack>

using namespace std;

int main() {
    int t, cnt = 0;
    cin >> t;
    stack<int> s;
    while (t) {
        s.push(t % 60);
        t /= 60;
        cnt++;
    }
    if (cnt < 3) {
        cnt = 3 - cnt;
        while (cnt--)
            s.push(0);
    }
    while (s.size()) {
        cout << s.top();
        s.pop();
        if (s.size())cout << ":";
    }
}