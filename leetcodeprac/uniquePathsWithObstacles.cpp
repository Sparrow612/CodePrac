//
//  uniquePathsWithObstacles.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/12.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int n=(int)obstacleGrid.size();
    if (!n) return 0;
    int m=(int)obstacleGrid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0)); // 第一步，明确dp的意义
    dp[0][0]=1; // 第二步，明确初始值
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (obstacleGrid[i][j]==1){
                dp[i][j]=0;
                continue;
            }
            if (i>0) dp[i][j]+=dp[i-1][j];
            if (j>0) dp[i][j]+=dp[i][j-1]; // 第三步，确定状态转移方程
        }
    }
    return dp[n-1][m-1];
}

//int main(){
//    
//}
