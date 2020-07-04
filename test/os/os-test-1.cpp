//
// Created by LOKKA on 2020/4/22.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
    int id;
    int arrivetime;  // 到达时间
    int servicetime; // 服务时间
    int finishtime;  // 完成时间
    int priority;    // 优先级
    char state;      // 状态， W等待 R运行 F完成
    Task(){}
    Task(int id, int at, int ct, int pr) :
            id(id), arrivetime(at), servicetime(ct),
            priority(pr), state('W') {}  //初始化为等待状态，运行时间为 0
};

bool operator < (const Task &a, const Task &b) {
    return  a.priority < b.priority;        //就绪队列，优先级高的在前
}

bool cmp(const Task &a, const Task &b) {
    return a.arrivetime < b.arrivetime;     //所有进程按到达时间排序
}

void updateTask(vector<Task> &tasks, Task &t) { // 更新作业状态
    int len = tasks.size();
    for (int i = 0; i < len; i++) {
        if (tasks[i].id == t.id) {
            tasks[i] = t;
            break;
        }
    }
}

void printState(Task &task, int time) {  // 打印作业表数据
    printf("时间片%3d", time);
    printf(" 作业ID:%3d  状态: %c  优先级:%3d  服务时间:%3d\n",
           task.id, task.state, task.priority, task.servicetime);
}

void priorityScheduling(vector<Task> &tasks, int n) {
    priority_queue<Task> readyque;      //就绪队列
    int len = tasks.size(), pcs = 0, now = 0;  // pcs记录当前处理到第几个作业
    for (int i = 0; ; i++) {   // 时间片
        if (readyque.empty() && pcs == len) break;
        for (int j = pcs; j < len; j++) {
            if (tasks[j].arrivetime == i) { // 作业在当前时间到达
                readyque.push(tasks[j]);   // 加入就绪队列
                pcs++;
            } else break;
        }
        if (!readyque.empty()) { // 就绪队列中有作业
            Task tmp = readyque.top();  //处理就绪队列中优先级最高的作业
            readyque.pop();
            tmp.state = 'R';     // 修改当前处理作业为运行状态
            printState(tmp, i);
            tmp.servicetime--;  // 修改当前作业运行时间
            if (tmp.servicetime == 0) {        // 作业处理完毕
                tmp.finishtime = i + 1;       // 记录完成的时间
                tmp.state = 'F';             // 修改状态为完成
                updateTask(tasks, tmp);     // 更新作业信息
                continue;
            } else {
                tmp.priority -= n;
                tmp.state = 'W';
                readyque.push(tmp);
                updateTask(tasks, tmp);

            }
        }
    }
}

int main() {
    int cnt = 0, at, ct, pr, n;
    vector<Task> tasks;
    while(~scanf("%d %d %d", &at, &ct, &pr)) {
        Task t = {cnt++, at, ct, pr};
        tasks.push_back(t);
        if (cnt == 5) break;
    }

    sort(tasks.begin(), tasks.end(), cmp);

    printf("请输入每运行一个时间单位优先权变化值n：\n");
    scanf("%d", &n);
    priorityScheduling(tasks, n);

    printf("  ID  到达时间  完成时间  周转时间\n");
    for (int i = 0; i < tasks.size(); i++) {
        printf("%4d   %5d    %5d   %5d\n",
               tasks[i].id, tasks[i].arrivetime, tasks[i].finishtime, tasks[i].finishtime - tasks[i].arrivetime);
    }
}