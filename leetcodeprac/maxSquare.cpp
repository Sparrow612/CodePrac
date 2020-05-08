//
//  maxSquare.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/8.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

//int maximalSquare(vector<vector<char>>& matrix) {
//    int n=(int)matrix.size();
//    if (!n) return 0;
//    int m=(int)matrix[0].size();
//    vector<vector<int>> dp(n, vector<int>(m,0));
//    int maxsquare=0;
//    for (int i=0;i<m;i++) {
//        dp[0][i]=matrix[0][i]-'0';
//        if (dp[0][i]) maxsquare=1;
//    }
//    for (int i=0;i<n;i++){
//        dp[i][0]=matrix[i][0]-'0';
//        if (dp[i][0]) maxsquare=1;
//    }
//    for (int i=1;i<n;i++){
//        for (int j=1;j<m;j++){
//            if (matrix[i][j]=='1'){
//                dp[i][j]=min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
//                maxsquare = max(dp[i][j]*dp[i][j], maxsquare);
//            }
//        }
//    }
//    return maxsquare;
//} // to be improved

int maximalSquare(vector<vector<char>>& matrix) {
    int n=(int)matrix.size();
    if (!n) return 0;
    int m=(int)matrix[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    int maxsquare=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (matrix[i][j]=='1'){
                dp[i+1][j+1]=min(dp[i][j], min(dp[i][j+1], dp[i+1][j]))+1;
                maxsquare = max(dp[i+1][j+1]*dp[i+1][j+1], maxsquare);
            }
        }
    }
    return maxsquare;
}

int main(){
    vector<char> line = {'0', '1'};
    vector<vector<char>> src={{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
    cout<<maximalSquare(src)<<endl;
}

// 二维矩阵中最大的正方形
// 动态规划解法
// 建议画画看
