/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start

class Solution
{
public:
// 非常丢人的一道题，我说我自己，wa了好多次
// 贪心思路，维护一个最远距离即可
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return true;
        }
        int far = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (i > far){
                return false;
            }
            else if (far >= n-1){
                return true;
            }
            far = max(far, nums[i]+i);
        }
        return far >= n-1;
    }
};
// @lc code=end
