#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// vector< vector<int> > zigzagLevelOrder(TreeNode* root) {
//     vector<TreeNode*> stk;
//     stk.push_back(root);
//     while (!stk.empty()){
//         int n = stk.size();
//         vector<int> line;
//         for (int i=0;i<n;i++){
//             line.push_back();
//         }
        
//     }
// }