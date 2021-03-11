//
//  isAVL.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/6.
//  Copyright © 2021 程荣鑫. All rights reserved.
// Leetcode 110. 平衡二叉树
// 思路：自底向上递归

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int heightOfTree(TreeNode* root){
    int left = heightOfTree(root->left);
    int right = heightOfTree(root->right);
    if (left != -1 && right != -1 && abs(left-right)<=1){
        return max(left, right)+1;
    }
    return -1;
}
bool isBalanced(TreeNode* root) {
    return heightOfTree(root) != -1;
}
