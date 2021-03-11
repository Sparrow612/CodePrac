//
//  calculate-II.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/11.
//  Copyright © 2021 程荣鑫. All rights reserved.
// Leetcode 227. 基本计算器

#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

unordered_map<char, int> priorities = {{'+', 1}, {'-', 1},{'*', 2},{'/', 2}};

string toPostExpr(string& s){
    stack<char> stk;
    string r;
    for (int i=0;i<s.length();i++){
        char c = s[i];
        if (c == ' ') continue;
        else if (c>='0' && c<='9'){
            while (c>='0'&&c<='9'){
                r += c;
                c = s[++i];
            }
            // 输出完一个整数
            r += ' ';
            i--;
        }else{
            if (stk.empty()|| priorities[stk.top()]<priorities[c]){
                stk.push(c);
            }
            else{
                while (!stk.empty() && priorities[stk.top()]>=priorities[c]){
                    r += stk.top();
                    stk.pop();
                }
                stk.push(c);
            }
        }
    }
    while (!stk.empty()){
        r += stk.top();
        stk.pop();
    }
    return r;
}
int calculate_II(string s) {
    string post = toPostExpr(s);
    stack<int> nums;
    int idx = 0;
    while (idx<post.length()){
        char c = post[idx];
        if (c<'0' || c>'9'){
            int b = nums.top();
            nums.pop();
            int a = nums.top();
            nums.pop();
            switch (c) {
                case '+':
                    nums.push(a+b);
                    break;
                case '-':
                    nums.push(a-b);
                    break;
                case '*':
                    nums.push(a*b);
                    break;
                case '/':
                    nums.push(a/b);
                    break;
                default:
                    break;
            }
        }else{
            int num = 0;
            while (c>='0'&&c<='9'){
                num = num*10 + (c-'0');
                c = post[++idx];
            }
            nums.push(num);
            // 整数后面必跟一空格，因此不用回退idx
        }
        idx++;
    }
    return nums.top();
}

// 上面的做法使用中缀表达式转后缀表达式，这是比较容易想到的做法，但是太过繁琐了
// 我们可以这样处理表达式：先算所有的乘除，后续的计算就是一系列加减

int calculate_III(string s){
    vector<int> stk;
    char sign = '+';
    int num = 0;
    int n = s.length();
    for (int i=0;i<n;i++){
        
        if (isdigit(s[i])){
            num = num*10 + (s[i] - '0');
        }
        
        if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1){
            // 说明一下这里为什么有||i==n-1，如果不加这个判断条件，那就就会漏掉最后一次非加运算
            switch (sign) {
                case '+':
                    stk.push_back(num);
                    break;
                case '-':
                    stk.push_back(-num);
                    break;
                case '*':
                    stk.back()*=num;
                    break;
                default:
                    stk.back()/=num;
                    break;
            }
            sign = s[i];
            num = 0;
        }
    }
    return accumulate(stk.begin(), stk.end(), 0);
}

int main(){
    string expr = "0-2147483647";
    cout<<calculate_III(expr)<<endl;
}
