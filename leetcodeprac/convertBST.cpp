//
//  convertBST.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/6.
//  Copyright © 2021 程荣鑫. All rights reserved.
// Leetcode 538. 把二叉搜索树转化为累加树
// 树的题目，无非就是遍历来遍历去，这里使用反向中序遍历就可以求得结果，不要想别的乱七八糟的递归

#include <stdio.h>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class ConvertBST {
private:
    int sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        tranverse(root);
        return root;
    }
    void tranverse(TreeNode* root){
        if (!root) return;
        tranverse(root->right);
        sum += root->val;
        root->val = sum;
        tranverse(root->left);
    }
};

int main(){
    TreeNode a(4), b(1), c(6);
    a.left = &b;
    a.right = &c;
    TreeNode* r = ConvertBST().convertBST(&a);
    cout<<r->val<<endl;
}
