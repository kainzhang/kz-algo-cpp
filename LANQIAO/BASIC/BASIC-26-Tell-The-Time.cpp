//
// Created by LOKKA on 2020/3/17.
//

#include<iostream>

using namespace std;

string trans(int x) {
    switch (x) {
        case 0:
            return "zero";
        case 1:
            return "one";
        case 2:
            return "two";
        case 3:
            return "three";
        case 4:
            return "four";
        case 5:
            return "five";
        case 6:
            return "six";
        case 7:
            return "seven";
        case 8:
            return "eight";
        case 9:
            return "nine";
        case 10:
            return "ten";
        case 11:
            return "eleven";
        case 12:
            return "twelve";
        case 13:
            return "thirteen";
        case 14:
            return "fourteen";
        case 15:
            return "fifteen";
        case 16:
            return "sixteen";
        case 17:
            return "seventeen";
        case 18:
            return "eighteen";
        case 19:
            return "nineteen";
        case 20:
            return "twenty";
        case 30:
            return "thirty";
        case 40:
            return "forty";
        case 50:
            return "fifty";
        case 60:
            return "o'clock";
    }
}

void print(int x) {
    if (x > 20 && x % 10) {
        cout << trans(x - x % 10) << " " << trans(x % 10) << " ";
    } else {
        cout << trans(x) << " ";
    }
}

int main() {
    int h, m;
    cin >> h >> m;
    print(h);
    if (m == 0) {
        print(60);
    } else {
        print(m);
    }
}