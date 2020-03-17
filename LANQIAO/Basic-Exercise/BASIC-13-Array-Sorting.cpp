//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int rand_partition(int *a, int lo, int hi) {
    int p = (round(1.0 * rand()) / RAND_MAX * (hi - lo) + lo);
    swap(a[p], a[lo]);
    int tmp = a[lo];
    while (lo < hi) {
        while (lo < hi && a[hi] > tmp) hi--;
        a[lo] = a[hi];
        while (lo < hi && a[lo] <= tmp) lo++;
        a[hi] = a[lo];
    }
    a[lo] = tmp;
    return lo;
}

void quick_sort(int *a, int lo, int hi) {
    if (lo < hi) {
        int mid = rand_partition(a, lo, hi);
        quick_sort(a, lo, mid - 1);
        quick_sort(a, mid + 1, hi);
    }
}

int main() {
    srand((unsigned) time(NULL));
    int n, a[205];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}