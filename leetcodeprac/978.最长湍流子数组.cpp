/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution {
public:
    int compareTo(int a, int b){
    if (a < b){
        return -1;
    }else if (a==b){
        return 0;
    }
    return 1;
}

int maxTurbulenceSize(vector<int>& arr) {
    int left = 0, right = 1;
    int n = arr.size();
    int pre, cur;
    int result = 1;
    while (right < n){
        // 需要剔除两个数相等的情况，例如[9,9]
        if (right <= left + 1 && arr[right]!=arr[right-1]) {
            pre = compareTo(arr[right-1], arr[right]);
        }
        else{
            cur = compareTo(arr[right-1], arr[right]);
            if (cur == pre) {
                left = right - 1;
            }
            else if (cur == 0){
                left = right;
            }
            else {
                pre = cur;
            }
        }
        result = max(result, right-left+1);
        right++;
    }
    return result;
}
};
// @lc code=end

