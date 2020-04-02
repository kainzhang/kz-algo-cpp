//
// Created by LOKKA on 2020/4/3.
//

#include <iostream>

using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    int a[40], i;
    for(i=1; x; i++) {
        a[i] = x % 10;
        x /= 10;
    }
    i--;
    for(int j=1; j<i/2+1; j++) {
        if(a[j] != a[i-j+1])
            return false;
    }
    return true;
}

int main() {
    cout << isPalindrome(121) << endl;
    cout << isPalindrome(-121) << endl;
    cout << isPalindrome(10) << endl;
}