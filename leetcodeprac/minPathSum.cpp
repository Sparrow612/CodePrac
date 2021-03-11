//
//  minPathSum.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/12.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int n=(int)grid.size();
    if (!n) return 0;
    int m=(int)grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m,0));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (i==0&&j==0) dp[i][j]=grid[i][j];
            else if (i==0) dp[i][j]=grid[i][j]+dp[i][j-1];
            else if (j==0) dp[i][j]=grid[i][j]+dp[i-1][j];
            else dp[i][j]=grid[i][j]+min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}

//int main(){
//
//}
// 动态规划做法非常简单
