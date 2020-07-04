//
// Created by LOKKA on 2020/7/3.
//

#include <bits/stdc++.h>
using namespace std;
const int mxN = 505;

// N:顶点数, M:边数, C1:起点, C2:终点
int N, M, C1, C2;
// G:邻接矩阵, d:起点至各点的最短距离, weight:点权, w:最大点权和, num:最短路径条数
int G[mxN][mxN], d[mxN], weight[mxN], w[mxN], num[mxN];
bool vis[mxN] = {false};

void dijkstra(int s) { // s 为起点

    fill(d, d + N, INT_MAX);  // 初始化 d 数组
    d[s] = 0;  // 起点到自身距离为 0
    w[s] = weight[s];  // 起点最大点权
    num[s] = 1;  // 起点至起点路径数为 1

    for (int i = 0; i < N; i++) {
        int u = -1, MIN = INT_MAX;

        // 遍历 N 个点, 寻找最小 d[]和对应顶点
        for (int j = 0; j < N; j++) {
            if (!vis[j] && d[j] < MIN) {
                MIN = d[j];
                u = j;
            }
        }
        if (u == -1) return;  // 未找到通路，剩下的顶点与起点不通
        vis[u] = true;  // 标记 u 已访问
        for (int v = 0; v < N; v++) {

            // 如果 v 未访问, 且 u - v 连通
            if (!vis[v] && G[u][v] != INT_MAX) {

                // 如果以 u 为中介点至 v 的距离小于已知 d[v]
                if (d[u] + G[u][v] < d[v]) {
                    d[v] = d[u] + G[u][v];  // 更新 d[v]
                    w[v] = w[u] + weight[v];  // 更新点权和
                    num[v] = num[u];  // 更新路径数
                } else if (d[u] + G[u][v] == d[v]) {  // 路径长度相同
                    w[v] = max(w[v], w[u] + weight[v]);  // 比较获取最大点权
                    num[v] += num[u];  // 路径数累加
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> C1 >> C2;

    // 读入点权, 即每个城市的救援队数量
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }

    // 初始化图 G, 边权为无穷大
    fill(G[0], G[0] + mxN * mxN, INT_MAX);

    // 读入边权, 即每两个城市的距离, 无向图双向赋值
    for (int i = 0; i < M; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        G[u][v] = G[v][u] = l;
    }
    dijkstra(C1);
    cout << num[C2] << " " << w[C2] << endl;
}
