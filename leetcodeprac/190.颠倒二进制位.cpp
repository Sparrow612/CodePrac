/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i=0;i<32;i++){
            res = ( res << 1 ) + (n&1);
            n = n >> 1;
            // >> 1 表示/2，<<1表示*2，不要">>/<< 2"!
        }
        return res;
    }
};
// @lc code=end

