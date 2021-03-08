//
// Created by 程荣鑫 on 2021/3/7.
//

#include <iostream>
#include <vector>

using namespace std;

class Partition {
private:
    vector<vector<string>> ans;
    vector<vector<bool>> dp;
    int n;
public:
    vector<vector<string>> partition(string s) {
        n = s.size();
        dp = vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i = 0;i<n;i++){
            for (int j=i;j<n;j++){
                if (j-i<=1){
                    dp[i][j] = s[i] == s[j];
                }
                else if (s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                }
            }
        }
        vector<string> path;
        dfs(s, path, 0);
        return ans;
    }
    void dfs(string& s, vector<string>& path, int idx){
        if (idx == n){
            vector<string>::iterator itl = path.begin();
            vector<string>::iterator itr = path.end();
            ans.push_back(vector<string>(itl, itr));
        }
        for(int i=idx;i<n;i++){
            if (dp[idx][i]){
                path.push_back(s.substr(idx, i+1));
                dfs(s, path, i+1);
                path.pop_back();
                break;
            }
        }
    }
};

int main(){
    Partition p;
    p.partition("aab");
}

