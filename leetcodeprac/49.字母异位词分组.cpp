/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
    // 这题倒没啥特别的，就是个语法题
    // 两个字母异位词，排序后得到的词语是一致的
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for (string s: strs){
            string o = s;
            sort(s.begin(), s.end());
            m[s].push_back(o);
        }
        vector< vector<string> > result;
        unordered_map<string, vector<string>>::iterator it;
        for (it=m.begin();it!=m.end();it++){
            result.emplace_back(it->second);
        }
        return result;
    }
};
// @lc code=end

