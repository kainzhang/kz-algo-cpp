//
// Created by LOKKA on 2020/7/20.
//

#include <bits/stdc++.h>
using namespace std;

struct Window {
    int end_time = 480, pop_time;
    queue<int> que;
};

vector<Window> win(25);
vector<int> pcs_time(1005), fin_time(1005);

int main() {
    int N, M, K, Q;
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    for(int i = 0; i < K; i++) {
        scanf("%d", &pcs_time[i]);
    }

    int step = 0;
    for(int i = 0; i < min(N * M, K); i++) {
        win[i % N].que.push(i);
        win[i % N].end_time += pcs_time[i];
        if(i < N) win[i].pop_time = pcs_time[i];
        fin_time[i] = win[i % N].end_time;
        step++;
    }

    for(int i = step; i < K; i++) {
        int idx = -1, MIN = INT_MAX;
        for(int j = 0; j < N; j++) {
            if(win[j].pop_time < MIN) {
                idx = j;
                MIN = win[j].pop_time;
            }
        }
        Window& t = win[idx];
        t.que.pop();
        t.que.push(i);
        t.end_time += pcs_time[i];
        t.pop_time += pcs_time[t.que.front()];
        fin_time[i] = t.end_time;
    }

    int num;
    while(Q--) {
        scanf("%d", &num);
        if(fin_time[num - 1] - pcs_time[num - 1] >= 1020) printf("Sorry\n");
        else printf("%02d:%02d\n", fin_time[num - 1] / 60, fin_time[num - 1] % 60);
    }
}
