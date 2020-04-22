//
// Created by LOKKA on 2020/3/16.
//

#include <iostream>
#include <cmath>
#include <stack>

using namespace std;
int symValue(char symbol) {
    switch(symbol) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default : return 0;
    }
}

float calc(float num1, char symbol, float num2) {
    switch(symbol) {
        case '+': return num1 + num2;
        case '-': return num1 - num2;
        case '*': return num1 * num2;
        case '/': return num1 / num2;
        case '^': return pow(num1, num2);
        default : return 0;
    }
}

int main() {
    string str, aimStr="";
    cin >> str;
    stack<char> symStack;
    stack<double> numStack;
    symStack.push('#');
    for(int i=0; i<str.length(); i++) {
        if (isdigit(str[i]) || str[i]=='.') {
            aimStr += str[i];
            if(!isdigit(str[i+1]) && str[i+1]!='.')
                aimStr += '#';
        } else {
            switch(str[i]) {
                case '(':
                    symStack.push(str[i]); break;
                case ')':
                    while(symStack.top() != '(') {
                        aimStr += symStack.top();
                        symStack.pop();
                    }
                    symStack.pop(); break;
                case '-':
                    if(i==0 || symValue(str[i-1]) || str[i-1]=='(') {
                        aimStr += "0#";
                        symStack.push('-');break;
                    }
                case '+': case '*': case '/': case '^':
                    while(symStack.top()!='#' && symValue(str[i]) <= symValue(symStack.top())) {
                        aimStr += symStack.top();
                        symStack.pop();
                    }
                    symStack.push(str[i]);
                default : break;
            }
        }
    }

    while(symStack.top()!='#') {
        aimStr += symStack.top();
        symStack.pop();
    }

    for(int i=0; i<aimStr.length(); ) {
        float temp = 0, dot = 0, num1, num2;
        int dotcount = 0;
        bool hvtemp = false;

        while(isdigit(aimStr[i])) {
            temp = temp*10 + aimStr[i++]-'0';
            hvtemp = true;
        }

        if(aimStr[i] == '.') {
            while(isdigit(aimStr[++i])) {
                dotcount++;
                dot = dot*10 + aimStr[i]-'0';
            }
            dot /= pow(10, dotcount);
            temp += dot;
            hvtemp = true;
        }

        if(hvtemp){
            numStack.push(temp);
            hvtemp = false;
        }

        switch(aimStr[i]) {
            case '#': i++; break;
            default :
                num1 = numStack.top(); numStack.pop();
                num2 = numStack.top(); numStack.pop();
                numStack.push(calc(num2, aimStr[i], num1));
                i++; break;
        }
    }
    cout << numStack.top() << endl;
}