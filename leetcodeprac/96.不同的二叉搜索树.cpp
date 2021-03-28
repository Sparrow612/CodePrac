/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    // 效仿95的做法，但是超时了
    // int helper(int start, int end){
    //     if (start > end){
    //         return 1; // 空节点
    //     }
    //     int result = 0;
    //     for(int i=start;i<=end;i++){
    //         int lefts = helper(start, i-1);
    //         int rights = helper(i+1, end);
    //         result += lefts*rights;
    //     }
    //     return result;
    // }
    // int numTrees(int n) {
    //     return helper(1, n);
    // }
    // 在法一方法上改进
    // 要清楚：对于i,只有i-1个可用节点！还有一个要用作根节点！！！
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = dp[1]= 1;
        for (int i=2;i<=n;i++){
            for (int j=0;j<i;j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
// @lc code=end

