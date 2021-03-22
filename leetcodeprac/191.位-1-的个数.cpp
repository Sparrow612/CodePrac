/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cur = 0;
        while (n!=0){
            cur ++;
            n &= n -1;
        }
        return cur;
    }
};
// @lc code=end

