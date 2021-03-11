//
//  constructMaximumBinaryTree.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/10.
//  Copyright © 2021 程荣鑫. All rights reserved.
// Leetcode 654&998 最大二叉树 I&II，II就是在I的基础上加个中序遍历就好了
#include <vector>
#include <iostream>

using namespace std;

vector<int> nums;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inorder(TreeNode* root){
    if (!root) return;
    inorder(root->left);
    nums.push_back(root->val);
    inorder(root->right);
}

TreeNode* construct(vector<int>& nums, int l, int r){
    if (l>=r) return nullptr;
    vector<int>::iterator maxIt = max_element(nums.begin()+l, nums.begin()+r);
    int idx = distance(nums.begin(), maxIt);
    TreeNode* root = new TreeNode(*maxIt);
    root->left = construct(nums, l, idx);
    root->right = construct(nums, idx+1, r);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return construct(nums, 0, nums.size());
}


