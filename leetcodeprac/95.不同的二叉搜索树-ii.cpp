/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.

 */
#include <vector>

using namespace std;

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }
    vector<TreeNode *> helper(int start, int end){
        vector<TreeNode *> result;
        if (start > end){
            result.push_back(nullptr); // 必须插入一个null，否则下面的for循环无法执行
            return result;
        }
        for (int i=start; i<=end;i++){
            vector<TreeNode *> lefts = helper(start, i-1);
            vector<TreeNode *> rights = helper(i+1, end);
            for (TreeNode* l: lefts){
                for (TreeNode* r: rights){
                    TreeNode* root = new TreeNode(i, l, r);
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};
// @lc code=end
