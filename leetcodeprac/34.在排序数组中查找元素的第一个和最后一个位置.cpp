/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = 0;
        int n = nums.size();
        while ( l<n ){
            if (nums[l] == target){
                r= l;
                while (r<n && nums[r] == target){ //访问数组时刻警惕越界
                    r++;
                }
                return {l, r-1};
            }
            l++;
        }
        return {-1, -1};
    }
};
// @lc code=end

