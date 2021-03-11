//
//  maxSumBST.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/6.
//  Copyright © 2021 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class MaxSumBST {
private:
    int ans = 0;
public:
    int maxSumBST(TreeNode* root) {
        tranverse(root);
        return ans;
    }
    /**
     * 返回值：int[4]
     * 0: 是否为BST
     * 1:最小值
     * 2:最大值
     * 3:和
     */
    vector<int> tranverse(TreeNode* root){
        if (root == nullptr){
            return {1, INT_MAX, INT_MIN, 0};
        };
        vector<int> left = tranverse(root->left);
        vector<int> right = tranverse(root->right);
        vector<int> res(4);
        if (left[0]&&right[0]&&left[2]<root->val&&root->val<right[1]){
            res[0] = 1;
            res[1] = min(left[1], root->val);
            res[2] = max(right[2], root->val);
            res[3] = left[3] + right[3] + root->val;
            ans = max(ans, res[3]);
        }else{
            res[0] = 0;
        }
        return res;
    }
};
