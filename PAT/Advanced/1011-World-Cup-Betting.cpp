//
// Created by LOKKA on 2020/4/17.
//

#include <iostream>

using namespace std;

char ch[] = {'W', 'T', 'L'};

int main() {
    double odds[5], ans = 1;
    int p[5] = {0};
    for (int i = 0; i < 3; i++) {
        scanf("%lf %lf %lf", &odds[0], &odds[1], &odds[2]);
        double max = odds[0];
        for (int j = 1; j < 3; j++)
            if (odds[j] > max) {
                p[i] = j;
                max = odds[j];
            }

        ans *= max;
    }
    for (int i = 0; i < 3; i++)
        printf("%c ", ch[p[i]]);
    printf("%.2f\n", (ans * 0.65 - 1) * 2);
}