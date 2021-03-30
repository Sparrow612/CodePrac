/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int left = 0,  right = 0;
        int num = strs.size();
        vector<int> ones;
        vector<int> zeros;

        for (string &s : strs)
        {
            int one = 0, zero = 0;
            for (char c : s)
            {
                if (c == '0')
                {
                    zero++;
                }
                else
                {
                    one++;
                }
            }
            ones.push_back(one);
            zeros.push_back(zero);
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i=0;i<num;i++){
            string& s = strs[i];
            for (int z = m;z>=zeros[i];z--){
                for (int o = n;o>=ones[i];o--){
                    dp[z][o] = max(dp[z][o], 1+dp[z-zeros[i]][o-ones[i]]);
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end
