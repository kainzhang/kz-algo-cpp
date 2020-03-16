//
// Created by LOKKA on 2020/3/16.
// 1016 程序运行时间

#include <iostream>

using namespace std;

int main() {
    int c1, c2, clk_tck = 100;
    cin >> c1 >> c2;
    int k = (int) (1.0 * (c2 - c1) / clk_tck + 0.5);
    int hh = k / 3600;
    int mm = (k % 3600) / 60;
    int ss = k % 60;
    printf("%02d:%02d:%02d", hh, mm, ss);
}