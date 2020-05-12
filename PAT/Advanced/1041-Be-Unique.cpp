//
// Created by LOKKA on 2020/4/23.
//

#include <iostream>

using namespace std;
int N, a[100005], b[100005], t;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        b[a[i]]++;
    }
    for (int i = 0; i < N; i++) {
        if (b[a[i]] == 1) {
            cout << a[i] << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}