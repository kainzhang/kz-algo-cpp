//
// Created by LOKKA on 2020/3/29.
//

#include <iostream>

using namespace std;

int main() {
   int a, b;
   cin >> a >> b;
   string str = to_string(a + b);
   int len = str.size();
   int rem = len % 3, i = 0;
   if (str[i] == '-')
       cout << str[i++];
   for(i; i < len; i++) {
       cout << str[i];
       if ((i + 1) % 3 == rem && i != len - 1)
           cout << ",";
   }
   cout << endl;
}