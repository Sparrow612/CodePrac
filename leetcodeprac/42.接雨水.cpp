/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    // int trap(vector<int>& height) {
    //     if (height.size() ==0)
    //         return 0;
    //     int n = height.size();
    //     vector<int> lefts(n);
    //     vector<int> rights(n);
    //     lefts[0] = height[0];
    //     for (int i =1;i<n;i++){
    //         lefts[i] = max(height[i],lefts[i-1]);
    //     }
    //     rights[n-1] = height[n-1];
    //     for (int i=n-2;i>=0;i--){
    //         rights[i] = max(height[i], rights[i+1]);
    //     }
    //     int ans = 0;
    //     for (int i =0;i<n;i++){
    //         ans += min(lefts[i], rights[i])-height[i];
    //     }
    //     return ans;
    // }
    int trap(vector<int>& height){
        if (height.size() ==0)
            return 0;
        int n = height.size(), ans = 0;
        stack<int> stk;
        for (int i = 0;i<n;i++){
            while (!stk.empty() && height[i] >height[stk.top()]){
                int cur = stk.top();
                stk.pop();
                if (stk.empty()){
                    break;
                }
                int dis = i-stk.top()-1;
                ans += (min(height[i], height[stk.top()])- height[cur])*dis;
            }
            stk.push(i);
        }
        return ans;
    }
    int trap_ptr(vector<int>& height){
        return 0;
    }
};
// @lc code=end

