/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount+1, amount+1);
        f[0] = 0;
        
        for (int c: coins){
            for(int i=c;i<=amount;i++){
                f[i] = min(f[i-c]+1, f[i]);
            }
        }
        return f[amount] > amount ? -1 : f[amount];
    }
};
// @lc code=end

