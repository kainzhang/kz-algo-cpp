//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char a[105], b[105], c[105];
    cin >> a >> b;
    int temp = 0, step = 0, lena = strlen(a) - 1, lenb = strlen(b) - 1;
    while (lena >= 0 || lenb >= 0) {
        int tempa = 0, tempb = 0;
        if (lena >= 0)
            tempa = a[lena--] - '0';
        if (lenb >= 0)
            tempb = b[lenb--] - '0';
        temp += tempa + tempb;
        c[step++] = temp % 10 + '0';
        temp /= 10;
    }
    c[step] = temp + '0';
    if (temp)step++;
    for (int i = step - 1; i >= 0; i--)
        cout << c[i];
}