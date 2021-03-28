/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
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
class BSTIterator {
private:
    vector<int> vals;
    int cur = -1, n = 0; 
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        vals.push_back(root->val);
        n++;
        inorder(root->right);
    }
    
public:
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return vals[++cur];
    }
    
    bool hasNext() {
        return (cur+1) < n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

