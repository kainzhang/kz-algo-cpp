//
// Created by LOKKA on 2020/7/2.
//

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<int> vec(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> vec[i];
    }
    // 枚举所有可能的狼人组合
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {

            // sign记录身份，liar保存说谎者
            vector<int> sign(N + 1, 1), liar;

            // 假设 i, j为狼人
            sign[i] = sign[j] = -1;

            // 自己说的与事实不符，记为说谎者
            for (int k = 1; k <= N; k++) {
                if (sign[abs(vec[k])] * vec[k] < 0) {
                    liar.push_back(k);
                }
            }

            // 说谎者数量为 2，且 1 狼人 1 人类，则 i, j为狼人成立
            if (liar.size() == 2 && sign[liar[0]] * sign[liar[1]] < 0) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;
}
