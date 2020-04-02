//
// Created by LOKKA on 2020/3/29.
//

#include <iostream>
#include <map>

using namespace std;
map<int, double> mp;

int main() {
    int k, n, T = 2;
    double a;
    while(T--) {
        scanf("%d", &k);
        while(k--) {
            scanf("%d %lf", &n, &a);
            mp[n] += a;
            if(mp[n] == 0)
                mp.erase(n);
        }
    }
    printf("%d", mp.size());
    for(map<int, double>::reverse_iterator it = mp.rbegin(); it != mp.rend(); it++)
        printf(" %d %.1f", it->first, it->second);
}