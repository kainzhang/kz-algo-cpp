//
// Created by LOKKA on 2020/4/17.
//

#include <iostream>
#include <algorithm>

using namespace std;

struct Time {
    int HH, MM, SS;
};

struct Record {
    char id[17];
    Time in, out;
};

bool cmp_in(const Record &a, const Record &b) {
    if (a.in.HH < b.in.HH)
        return true;
    else if (a.in.MM < b.in.MM)
        return true;
    else
        return (a.in.SS < b.in.SS);
}

bool cmp_out(const Record &a, const Record &b) {
    if (a.out.HH > b.out.HH)
        return true;
    else if (a.out.MM > b.out.MM)
        return true;
    else
        return (a.out.SS > b.out.SS);
}

int main() {
    int M;
    scanf("%d", &M);
    Record r[100];
    for (int i = 0; i < M; i++) {
        scanf("%s %d:%d:%d %d:%d:%d",
              r[i].id, &r[i].in.HH, &r[i].in.MM, &r[i].in.SS,
              &r[i].out.HH, &r[i].out.MM, &r[i].out.SS
        );
    }
    sort(r, r + M, cmp_in);
    cout << r[0].id << " ";
    sort(r, r + M, cmp_out);
    cout << r[0].id << endl;
}