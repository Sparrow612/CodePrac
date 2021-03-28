/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
// 对于有些数组题而言，可以先上来sort一下，题目会更好做！
class Solution
{
public:
    vector<vector<int> > merge(vector<vector<int> > &intervals)
    {
        vector<vector<int> > result;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) -> bool {
            return a[0] < b[0];
        });
        for (vector<int> interval : intervals)
        {
            if (result.empty() || result.back()[1] < interval[0])
            {
                result.push_back(interval);
            }
            else
            {
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }
        return result;
    }
};
// @lc code=end
