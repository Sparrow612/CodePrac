//
//  kthLargest.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/11.
//  Copyright © 2021 程荣鑫. All rights reserved.
// Leetcode 剑指Offer 54. 二叉树的第k大节点

#include <stdio.h>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int cur = 0, ans = 0;


int kthLargest(TreeNode* root, int k) {
    traverse(root, k);
    return ans;
}
void traverse(TreeNode* root, int k){
    if (!root) return;
    traverse(root->right, k);
    
    if (cur == k) return;  // return 的位置很重要！！
    ans = root->val;
    cur++;
    
    traverse(root->left, k);
}