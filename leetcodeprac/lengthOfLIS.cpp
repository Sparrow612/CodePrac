//
//  lengthOfLIS.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/4.
//  Copyright © 2021 程荣鑫. All rights reserved.
//
// Leetcode 300. 最长递增子序列
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int res = 1;
    vector<int> dp(nums.size(), 1);
    for (int i=1;i<nums.size();i++){
        int maxPre = 0;
        for (int j = 0;j<i;j++){
            if (nums[i] > nums[j]){
                maxPre = max(maxPre, dp[j]);
            }
        }
        dp[i] = maxPre + 1;
        res = max(dp[i], res);
    }
    return res;
}
