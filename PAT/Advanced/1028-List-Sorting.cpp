//
// Created by LOKKA on 2020/4/20.
//

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

struct student {
    int id, grade;
    char name[10];
};

bool cmp_1(const student &a, const student &b) {
    return a.id < b.id;
}

bool cmp_2(const student &a, const student &b) {
    int t = strcmp(a.name, b.name);
    if (!t) return cmp_1(a, b);
    else if (t < 0) return true;
    return false;
}

bool cmp_3(const student &a, const student &b) {
    if (a.grade == b.grade)
        return cmp_1(a, b);
    return a.grade < b.grade;
}

int main() {
    int N, C;
    scanf("%d %d", &N, &C);
    student *s = new student[N];
    for (int i = 0; i < N; i++)
        scanf("%d %s %d", &s[i].id, s[i].name, &s[i].grade);

    switch (C) {
        case 1 :
            sort(s, s + N, cmp_1);
            break;
        case 2 :
            sort(s, s + N, cmp_2);
            break;
        case 3 :
            sort(s, s + N, cmp_3);
            break;
    }
    for (int i = 0; i < N; i++)
        printf("%06d %s %d\n", s[i].id, s[i].name, s[i].grade);
}