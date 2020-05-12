//
//  minFallingPathSum.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/12.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int minFallingPathSum(vector<vector<int>>& A) {
    int n=(int)A.size();
    if (!n) return 0;
    int m=(int)A[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i=0;i<m;i++) dp[0][i]=A[0][i];
    for (int i=1;i<n;i++){
        for (int j=0;j<m;j++){
            int shortest=dp[i-1][j];
            if (j>0) shortest=min(shortest, dp[i-1][j-1]);
            if (j+1<m) shortest=min(shortest, dp[i-1][j+1]);
            dp[i][j]=A[i][j]+shortest;
        }
    }
    return *min_element(dp[n-1].begin(), dp[n-1].end());
}

//int main(){
//    
//}
