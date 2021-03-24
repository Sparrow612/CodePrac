/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132模式
 */

// @lc code=start
class Solution {
public:
// 思路，枚举3，找到小于3最大的2，最小的1
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, nums[0]);
        for (int i=1;i<n;i++){
            dp[i] = min(nums[i], dp[i-1]);
        } // 使用动态规划，找到每个元素的leftMin
        stack<int> stk;
        int two = INT_MIN;
        for (int i=n-1;i>=0;i--){
            while (!stk.empty() && nums[i]>stk.top()){
                two = stk.top();
                stk.pop();
            } // 维护单调栈
            stk.push(nums[i]);
            if (two>dp[i]){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

