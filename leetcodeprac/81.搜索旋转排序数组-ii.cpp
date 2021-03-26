/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int cur;
        int n = nums.size();
        if (target>=nums[0]){
            cur = 0;
            while(1){
                if (nums[cur]==target){
                    return true;
                }
                cur++;
                if (cur>=n || nums[cur] > target || nums[cur] < nums[cur-1]){
                    break;
                }
            }
        }
        else if (target<=nums[n-1]){
            cur = n-1;
            while (1){
                if (nums[cur]==target){
                    return true;
                }
                cur--;
                if (cur < 0 || nums[cur] < target || nums[cur] > num[cur+1]){
                    break;
                }
            }
        }
        return false;
    }
};
// @lc code=end

