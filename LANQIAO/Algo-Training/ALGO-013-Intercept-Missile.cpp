//
// Created by LOKKA on 2020/3/20.
// 拦截导弹 (最大上升、下降子序列

#include <iostream>
#include <cstdio>

using namespace std;

int arr[10000], dpm[1000], dps[1000], i = 0, msl = 0, sys = 0;

int main() {
    while (~scanf("%d", &arr[i])) {
        dpm[i] = dps[i] = 1;
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i])
                dpm[i] = max(dpm[i], dpm[j] + 1);
            else
                dps[i] = max(dps[i], dps[j] + 1);
        }
        msl = max(msl, dpm[i]);
        sys = max(sys, dps[i]);
        i++;
    }
    printf("%d\n%d\n", msl, sys);
//    for(int k=0; k<i; k++) {
//        printf("%d %d\n", dpm[k], dps[k]);
//    }
}