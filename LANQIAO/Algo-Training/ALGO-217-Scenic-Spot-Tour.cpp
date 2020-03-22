//
// Created by LOKKA on 2020/3/17.
//

#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);
    for (int i = n - 1; i >= 0; i--)
        printf("%d ", arr[i]);
}