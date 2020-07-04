//
// Created by LOKKA on 2020/5/17.
//

#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e2;
int n, t, p[mxN], m[mxN][mxN], s[mxN][mxN];

void solve() {
    for(int i=n-1; i>=1; i--) {
        for(int j=i+1; j<=n; j++) {
            m[i][j] = 1 << 30;
            for(int k=i; k<j; k++) {
                int tmp = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if(tmp < m[i][j]) {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print_table(int a[][100], int n) {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++)
            printf("%6d ", a[i][j]);
        printf("\n");
    }
}

void print_ans(int x, int y) {
    if (x == y) {
        cout << "A[" << x << "]";
        return;
    }
    cout << "(";
    print_ans(x, s[x][y]);
    print_ans(s[x][y] + 1, y);
    cout << ")";
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> p[i] >> t;
    p[n] = t;
    solve();
    cout << "Min: " << m[1][n] << endl;
    cout << "Ans: ";
    print_ans(1, n);
//    cout << "Array M: " << endl;
//    print_table(m, n);
//    cout << endl << "Array S: " << endl;
//    print_table(s, n);
}





