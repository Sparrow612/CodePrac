/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        for (int i = 0;i<m/2;i++){
            for(int j=0;j<n;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = tmp;
            }
        }
        for (int i = 0;i<m-1;i++){
            for (int j=i+1;j<n;j++){
                int tmp = matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
// @lc code=end

