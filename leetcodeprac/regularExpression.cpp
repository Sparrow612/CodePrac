//
//  regularExpression.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/2.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 分类讨论：
// 1. p[j]=s[i] or p[j]='.' dp[i][j]=dp[i-1][j-1]
// 2. p[j]='*':
//      1. p[j-1]=s[i]||p[j-1]='*':  dp[i][j]=dp[i-1][j]||dp[i][j-1]||dp[i][j-2]
//          dp[i-1][j]表示*匹配一个或多个 dp[i][j-1]表示*匹配一个 dp[i][j-2]表示0个
//      2. else: dp[i][j]=dp[i][j-2]
//          *表示0

bool isMatch(string s, string p) {
    int m=(int)s.size(), n=(int)p.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    dp[0][0]=1; // 初始化
    for (int i=0;i<n;i++){
        dp[0][i+1]=p[i]=='*'&&dp[0][i-1]; // 初始化，*全部表示0
    }
    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (p[j-1]==s[i-1]||p[j-1]=='.') dp[i][j]=dp[i-1][j-1]; // 相等或者是通配符
            else if(p[j-1]=='*'){ // *不会出现在第一个
                if (p[j-2]!=s[i-1]&&p[j-2]!='.') dp[i][j]=dp[i][j-2]; // *表示0个
                else{ // p[j-1]是通配符.或者与s[i]相等
                    dp[i][j]=dp[i-1][j]||dp[i][j-1]||dp[i][j-2]; // * 号表示0个、1个、多个
                }
            }
        }
    }
    return dp[m][n];
}

int main(){
    cout<<isMatch("aab", "a.")<<endl;
}

// 相当经典的正则表达式匹配题，有空整理一下！
// 动态规划解法

