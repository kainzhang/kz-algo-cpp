//
// Created by LOKKA on 2020/4/17.
//

#include <iostream>

using namespace std;

int main() {
    int n, now = 0, aim, ans = 0;
    while (~scanf("%d", &n)) {
        while (n--) {
            scanf("%d", &aim);
            if (aim > now) {
                ans += (aim - now) * 6 + 5;
            } else {
                ans += (now - aim) * 4 + 5;
            }
            now = aim;
        }
        cout << ans << endl;
    }
}