//
// Created by LOKKA on 2020/4/12.
// 求先序排列


#include <iostream>

using namespace std;

string in, post, pre = "";

void getPreorder(int root, int l, int r) {
    if (l > r) return;
    int i = r;
    while (post[root] != in[i])
        i--;
    pre += post[root];

    getPreorder(root - 1 + i - r, l, i - 1);
    getPreorder(root - 1, i + 1, r);
}

int main() {
    cin >> in >> post;
    getPreorder(post.length() - 1, 0, in.length() - 1);
    cout << pre;
}