//
// Created by LOKKA on 2020/3/16.
//

#include <cstdio>

int main() {
    int ag, as, ak, bg, bs, bk;
    scanf("%d.%d.%d %d.%d.%d",
          &ag, &as, &ak, &bg, &bs, &bk);
    ak += bk;
    if (ak >= 29) {
        as += ak / 29;
        ak %= 29;
    }
    as += bs;
    if (as >= 17) {
        ag += as / 17;
        as %= 17;
    }
    ag += bg;
    printf("%d.%d.%d\n", ag, as, ak);
}