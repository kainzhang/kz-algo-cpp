//
// Created by LOKKA on 2020/4/4.
//

#include <iostream>

using namespace std;

int main() {
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    double x_1, y_1, x_2, y_2, ans = 0;
    x_1 = max(min(x1, x2), min(x3, x4));
    y_1 = max(min(y1, y2), min(y3, y4));
    x_2 = min(max(x1, x2), max(x3, x4));
    y_2 = min(max(y1, y2), max(y3, y4));
    if (x_1 < x_2 && y_1 < y_2)
        ans = (y_2 - y_1) * (x_2 - x_1);
    printf("%.2f\n", ans);
}