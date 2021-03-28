/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution {
public:
    void swap(vector<int>& nums, int l, int r){
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return;
        int idx = n-2;
        while (idx>=0 && nums[idx]>=nums[idx+1]){
            idx--;
        }
        
        if (idx >= 0 ){
            int cur = n-1;
            while (cur>idx && nums[cur]<=nums[idx]){
                cur--;
            }
            swap(nums, idx, cur);
        } 
        int l = idx+1, r = n-1;
        while (l<r){
            swap(nums, l, r);
            l++;
            r--;
        }
    }
};
// @lc code=end

