//
//  calculate.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/10.
//  Copyright © 2021 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int calculate(string s) {
    stack<int> ops;
    ops.push(1);
    int res = 0, sign = 1;
    for (int i=0;i<s.length();i++){
        char c = s[i];
        int sum = 0;
        switch(c){
            case '+':
                sign = ops.top();
                break;
            case '-':
                sign = -ops.top();
                break;
            case '(': // 入栈
                ops.push(sign);
                break;
            case ')': // 出栈
                ops.pop();
                break;
            case ' ':
                break;
            default:
                while (c>='0'&& c<='9'){
                    sum = sum*10 +(c - '0');
                    c = s[++i];
                }
                i--;
                break;
        }
        res += sign*sum;
    }
    return res;
}

//int main(){
//    cout<<calculate("2-1 + 1")<<endl;
//}
