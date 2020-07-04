//
// Created by LOKKA on 2020/5/13.
//

#include <bits/stdc++.h>
using namespace std;
const int N = 1e2;

struct Task {
    vector<int> blk_use; // 页表
    bool active;        // 是否可用

    Task() {
        active = false; // 默认未激活
    }
};

void init_memory(vector<int>& blk, int& busy_blk) {
      //1 表示已分配  0 表示未分配
//    cout << "请输入10 * 10矩阵表示空间各物理块情况:" << endl;
//    for (int i = 0; i < 10; i++) {
//        for (int j = 0; j < 10; j++) {
//            cin >> blk[i * 10 + j];
//        }
//    }

    for (int i = 0; i < 30; i++) { // 初始分配
        int tmp = rand() % N;
        if (!blk[tmp]) {
            blk[tmp] = true;
            busy_blk++;
        }
    }
}

void print_status(vector<int>& blk) {
    printf("当前内存情况:\n");
    for (int i = 0; i < N; i++) {
        printf("%3d", blk[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

void alloc_blk(vector<Task>& tasks, vector<int>& blk, int& busy_blk) {
    int task_idx, page_size;
    printf("请输入作业号和作业大小:");
    cin >> task_idx >> page_size;

    if (tasks[task_idx].active) {
        printf("该作业已存在\n");
        return;
    } else if (page_size > N - busy_blk) {
        printf("内存不足，分配失败\n");
        return;
    }

    tasks[task_idx].active = true;

    int page_cnt = 0;
    for (int i = 0; i < N, page_cnt < page_size; i++) {
        if (!blk[i]) {     // 判断块状态
            blk[i] = 1;
            tasks[task_idx].blk_use.push_back(i); // 分配内存
            page_cnt++;
            busy_blk++;
        }
    }
}

void free_blk(vector<Task>& tasks, vector<int>& blk, int& busy_blk) {
    int task_idx;
    printf("请输入作业号:");
    cin >> task_idx;

    if (!tasks[task_idx].active) {
        printf("该作业不存在\n");
        return;
    }

    while(!tasks[task_idx].blk_use.empty()) {
        int tmp = tasks[task_idx].blk_use.back();
        tasks[task_idx].blk_use.pop_back();
        blk[tmp] = 0;
        busy_blk--;
    }
    tasks[task_idx].active = false;
}

void print_menu() {
    printf("\n1.内存状态 ");
    printf("2.分配内存 ");
    printf("3.结束作业\n");
    printf("请输入指令(0退出):");
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    srand((unsigned) time(NULL));

    int busy_blk = 0; //已分配内存块数
    vector<int> blk(N, 0);  //内存块状态全部初始化为 0
    init_memory(blk, busy_blk);

    vector<Task> tasks(N);    // 作业表

    print_menu();
    int choice;
    while(cin >> choice, choice) {
        switch (choice) {
            case 1: print_status(blk); break;
            case 2: alloc_blk(tasks, blk, busy_blk); break;
            case 3: free_blk(tasks, blk, busy_blk); break;
            default: break;
        }
        print_menu();
    }
}