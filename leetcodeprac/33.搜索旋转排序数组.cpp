/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int cur;
        int n = nums.size();
        if (target>=nums[0]){
            cur = 0;
            while (1){
                if (nums[cur] == target){
                    return cur;
                }
                cur++;
                if (cur >= n || nums[cur]> target || nums[cur]< nums[cur-1]){
                    break;
                }
            }
        }
        else if (target<=nums[n-1])
        {
            cur = n-1;
            while (1){
                if (nums[cur] == target){
                    return cur;
                }
                cur--;
                if (cur < 0 || nums[cur]<target || nums[cur]>nums[cur+1]){
                    break;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

