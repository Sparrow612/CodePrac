//
//  buildTree.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/8.
//  Copyright © 2021 程荣鑫. All rights reserved.
// 构造二叉树，很基础的题目

// 说说这道题暴露出的问题：基础不扎实，第39行和第41行的两个数据一开始写错了，很明显是代码写少了
// 没事多拿出来练练

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

class Builder {
private:
    vector<int> pre, in;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        in = inorder;
        pre = preorder;
        int n = preorder.size();
        return build(0, n-1, 0, n-1);
    }
    TreeNode* build(int l1, int r1, int l2, int r2){
        // 下次写代码变量名不能乱起
        if (l1>r1) return nullptr;
        TreeNode* root = new TreeNode(pre[l1]);
        vector<int>::iterator idx = find(in.begin(), in.end(), pre[l1]);
        
        int left = idx - (in.begin()+l2); // 计算左树的节点个数
        root->left = build(l1+1, l1+left, l2, l2+left-1);
        root->right = build(l1+left+1, r1, l2+left+1, r2); // 中序数组l2+left的节点是root，要跳过！！
        return root;
    }
};

//int main(){
//    vector<int> preorder = {3,9,20,15,7};
//    vector<int> inorder = {9, 3, 15, 20, 7};
//    Builder().buildTree(preorder, inorder);
//}
