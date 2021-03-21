#include <iostream>
#include <vector>

// 73. 矩阵置零
// 难度
// 中等

// 428

// 收藏

// 分享
// 切换为英文
// 接收动态
// 反馈
// 给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

// 进阶：

// 一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
// 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
// 你能想出一个仅使用常量空间的解决方案吗？

using namespace std;

void setZeroes(vector< vector<int> >& matrix) {
        bool fir_col = false;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i=0;i<m;i++){
            if (!matrix[i][0]){
                fir_col = true;
            }
            for (int j=1;j<n;j++){
                if (!matrix[i][j]){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i=m-1;i>=0;i--){
            for (int j =1;j<n;j++){
                if (!matrix[i][0] || !matrix[0][j]){
                    matrix[i][j] = 0;
                }
            }
            if (fir_col){
                matrix[i][0] = 0;
            }
        }
    }