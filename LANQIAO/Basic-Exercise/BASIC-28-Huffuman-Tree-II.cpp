//
// Created by LOKKA on 2020/3/17.
//

#include <iostream>
#include <map>
using namespace std;

map<int ,int> mp;

int main() {
    int n, t, ans=0;
    cin >> n;
    while(n--) {
        cin >> t;
        mp[t] ++;
    }
    int flag = 0;
    map<int, int>::iterator it;
    for(it = mp.begin(); it != mp.end(); it++) {
        if(flag) {
            mp[it->first + flag]++;
            mp[it->first]--;
            ans += flag + it->first;
            flag = 0;
        }
        if(it->second >= 2) {
            int tmp = it->second / 2;
            mp[it->first * 2] += tmp;
            ans += it->first * 2 * tmp;
            mp[it->first] %= 2;
        }
        if(it->second){
            flag = it->first;
            mp[it->first]--;
        }
    }
    cout << ans << endl;
}