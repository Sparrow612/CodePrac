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

// Leetcode 1530. 好叶子节点的数量
// 这道题采用后序遍历的方法，先后访问左右树获取根节点，然后比对距离<=distance的节点对

vector<int> dfs(TreeNode *root, int distance, int &ans)
{
    vector<int> res;
    if (!root)
        return res;
    if (!root->left && !root->right)
    {
        res.push_back(0); // 如果是叶节点，加入数组
    }
    else
    {
        vector<int> left = dfs(root->left, distance, ans);
        for (int i = 0; i < left.size(); i++)
        {
            res.push_back(left[i] + 1);
        } // 得到左树的叶子
        vector<int> right = dfs(root->right, distance, ans);
        for (int i = 0; i < right.size(); i++)
        {
            res.push_back(right[i] + 1);
        } // 得到右树的叶子
        for (int i = 0; i < left.size(); i++)
        {
            for (int j = 0; j < right.size(); j++)
            {
                if (left[i] + right[j] + 2 <= distance)
                    ans++;
            }
        }
        // 看看有无距离<=distance的叶子对
    }
    return res;
}

int countPairs(TreeNode *root, int distance)
{
    int ans = 0;
    dfs(root, distance, ans);
    return ans;
}
