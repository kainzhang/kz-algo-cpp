//
// Created by LOKKA on 2020/5/26.
//

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a_num, a_den, b_num, b_den;
char syb[] = {'+', '-', '*', '/'};

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

void print_rnum(ll num, ll den) {
    ll t = gcd(abs(num), abs(den));
    num /= t, den /= t;
    if (num < 0) printf("(");
    if (den == 1) {
        printf("%lld", num);
    } else if (abs(num) > den) {
        printf("%lld %lld/%lld", num / den, abs(num) % den, den);
    } else {
        printf("%lld/%lld", num, den);
    }
    if (num < 0) printf(")");
}

void print_res(int s) {
    bool is_minus = false;
    switch (syb[s]) {
        case '-': {
            b_num = -b_num;
            is_minus = true;
        }
        case '+': {
            ll num = a_num * b_den + b_num * a_den;
            ll den = a_den * b_den;
            print_rnum(num, den);
            if (is_minus) b_num = -b_num;
            break;
        }
        case '/': {
            if (b_num < 0) {
                b_num = -b_num;
                b_den = -b_den;
            }
            swap(b_num, b_den);
        }
        case '*': {
            ll num = a_num * b_num;
            ll den = a_den * b_den;
            print_rnum(num, den);
            break;
        }
    }
    printf("\n");
}


int main() {
    scanf("%lld/%lld %lld/%lld", &a_num, &a_den, &b_num, &b_den);
    ll t = gcd(abs(a_num), abs(a_den));
    a_num /= t, a_den /= t;
    t = gcd(abs(b_num), abs(b_den));
    b_num /= t, b_den /= t;

    for (int i = 0; i < 4; i++) {
        print_rnum(a_num, a_den);
        printf(" %c ", syb[i]);
        print_rnum(b_num, b_den);
        printf(" = ");
        if (i == 3 && !b_num) {
            printf("Inf\n");
        } else {
            print_res(i);
        }
    }
}