/*
 * @lc app=leetcode.cn id=802 lang=cpp
 *
 * [802] 找到最终的安全状态
 */

// @lc code=start
class Solution {
private:
    vector<bool> vis;
    vector<int> state;
public:
    int dfs(vector<vector<int>>& graph, int n){
        if (vis[n]) return state[n] = 0; // 发现环
        if (state[n]!=-1) return state[n];

        vis[n] = true;
        int res;
        for (int i: graph[n]){
            res = dfs(graph, i);
            if (res == 0) return state[n] = 0;
        }
        vis[n] = false;
        return state[n] = 1;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vis.assign(n, false);
        state.assign(n, -1);
        for (int i=0;i<n;i++){
            if (dfs(graph, i) == 1){
                res.push_back(i);
            }
        }
        return res;
    }
};
// @lc code=end

