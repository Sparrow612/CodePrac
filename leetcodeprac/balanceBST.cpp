//
//  balanceBST.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/6.
//  Copyright © 2021 程荣鑫. All rights reserved.
// Leetcode 1382. 将二叉搜索树变平衡
// 千万不要傻乎乎的去旋转！你编码实力没那么硬！
// 思路：中序遍历二叉搜索树，建立AVL树

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BalanceBST {
private:
    vector<int> tree;
public:
    TreeNode* balanceBST(TreeNode* root) {
        if (!root) return nullptr;
        inOrder(root);
        return buildTree(0, tree.size()-1);
    }
    TreeNode* buildTree(int start, int end){
        if (start>end){
            return nullptr;
        }
        int mid = (start+end) /2;
        TreeNode* root = new TreeNode(tree[mid]);
        root->left = buildTree(start, mid-1);
        root->right = buildTree(mid+1, end);
        return root;
    }
    
    void inOrder(TreeNode* root){
        if (!root) return;
        inOrder(root->left);
        tree.push_back(root->val);
        inOrder(root->right);
    }

};

//int main(){
//    TreeNode a(1);
//    TreeNode b(2);
//    TreeNode c(3);
//    TreeNode d(4);
//    a.right = &b;
//    b.right = &c;
//    c.right = &d;
//    TreeNode* r = BalanceBST().balanceBST(&a);
//}
