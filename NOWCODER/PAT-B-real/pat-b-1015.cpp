//
// Created by LOKKA on 2020/3/16.
// 1015 反转链表

#include <cstdio>

using namespace std;
struct Node {
    int data, next;
};
Node a[100005];
int flag = 0, fa, k, n, t, pre;

void func(int addr) {
    int i, ta = addr;
    for (i = 0; i < k; i++) {
        if (ta == -1) break;
        ta = a[ta].next;
    }
    if (i == k) {
        ta = a[addr].next;
        int na, pa = addr;
        for (int i = 1; i < k; i++) {
            if (i == k - 1) {
                if (!flag) {
                    fa = ta;
                    flag++;
                } else {
                    a[pre].next = ta;
                }
            }
            na = a[ta].next;
            a[ta].next = pa;
            pa = ta;
            ta = na;
        }
        a[addr].next = ta;
        pre = addr;
        func(ta);
    }
}

int main() {
    scanf("%5d %d %d", &fa, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%5d", &t);
        scanf("%d %5d", &a[t].data, &a[t].next);
    }
    func(fa);
    while (fa != -1) {
        printf("%05d %d ", fa, a[fa].data);
        if (a[fa].next != -1) {
            printf("%05d\n", a[fa].next);
        } else {
            printf("-1\n");
        }
        fa = a[fa].next;
    }
}