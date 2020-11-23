//
// Created by Kain Zhang on 2020/9/12.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        stack<int> num;
        stack<char> sym;
        string str;
        cin >> str;
        for (char &c : str) {
            if (isdigit(c)) {
                if (!sym.empty() && sym.top() == '-') {
                    num.push(-1 * (c - '0'));
                } else {
                    num.push(c - '0');
                }
                if (!sym.empty() && (sym.top() == 'x' || sym.top() == '/')) {
                    char ss = sym.top();
                    sym.pop();
                    int a = num.top();
                    num.pop();
                    int b = num.top();
                    num.pop();
                    if (ss == 'x') {
                        num.push(b * a);
                    } else {
                        num.push(b / a);
                    }
                }
            } else {
                sym.push(c);
            }
        }
        while (num.size() > 1) {
            int a = num.top();
            num.pop();
            int b = num.top();
            num.pop();
            num.push(a + b);
        }
        //cout << num.top() << endl;
        cout << (num.top() == 24 ? "Yes" : "No") << endl;
    }
}

/*
10
9+3+4x3
5+4x5x5
7-9-9+8
5x6/5x4
3+5+7+9
1x1+9-9
1x9-5/9
8/5+6x9
6x7-3x6
6x4+4/5
 */