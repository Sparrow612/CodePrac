//
//  generateBrackets.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/9.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> generateParenthesis(int n) {
    vector<vector<string>> repo;
    vector<string> ini(1,"");
    repo.push_back(ini);
    for (int p=1;p<=n;p++){
        vector<string> cur;
        for (int i=0;i<p;i++){
            vector<string> src1=repo[i];
            vector<string> src2=repo[p-1-i];
            for (string s1:src1){
                for (string s2:src2)
                    cur.push_back("("+s1+")"+s2);
            }
        }
        repo.push_back(cur);
    }
    return repo[n];
}

//int main(){
//    int n=3;
//    vector<string> res=generateParenthesis(n);
//    for (string s:res)
//        cout<<s<<endl;
//}

// 动态规划
