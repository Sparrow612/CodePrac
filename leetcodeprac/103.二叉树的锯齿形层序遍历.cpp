/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if (!root) return ans;
        q.push(root);
        bool toLeft = false;
        while (!q.empty()){
            int size = q.size();
            deque<int> level;
            for (int i = 0;i<size;i++){
                TreeNode *t = q.front();
                if (toLeft){
                    level.push_front(t->val);
                }
                else{
                    level.push_back(t->val);
                }
                if (t->left)q.push(t->left);
                if (t->right)q.push(t->right);
                q.pop();    
            }
            toLeft = !toLeft;
            ans.push_back(vector<int>(level.begin(), level.end()));
        }
        return ans;
    }
};
// @lc code=end

