/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    // dp[i][j]取决于：
    // dp[i-1][j]+1, 对应插入操作
    // dp[i][j-1]+1，对应删除操作
    // dp[i-1][j-1]+1, 对应修改操作
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=0;i<=m;i++){
            dp[i][0] = i;
        }

        for (int j=0;j<=n;j++){
            dp[0][j] = j;
        }

        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                if (word1[i-1]==word2[j-1]){
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]-1))+1;
                }else{
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]))+1;
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

