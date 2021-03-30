/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m = {{0, 0}, {1, 0}, {2, 0}};
        for (int n: nums){
            m[n]++;
        }
        int cur;
        for (int i=0;i<3;i++){
            for(int j=0;j<m[i];j++){
                nums[cur++] = i;
            }
        }
    }
};
// @lc code=end

