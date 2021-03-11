//
//  convertBiNode.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/6.
//  Copyright © 2021 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree2List {
private:
    TreeNode* newRoot = NULL, *prev;
public:
    TreeNode* convertBiNode(TreeNode* root) {
        convert(root);
        return newRoot;
    }

    void convert(TreeNode* root){
        if (root == NULL)
            return;
        convert(root->left);
        if (newRoot == NULL){
            newRoot = root;
        }else{
            prev->right = root;
            root->left = NULL;
        }
        prev = root;
        convert(root->right);
    }
};

    
