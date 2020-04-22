//
// Created by LOKKA on 2020/3/17.
//

#include <cstdio>

void GetTwoInts(int &a, int &b) {
    scanf("%d %d", &a, &b);
}

int main() {
    int a, b;
    GetTwoInts(a, b);
    printf("%d\n", a + b);
}