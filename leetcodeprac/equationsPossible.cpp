//
//  equationsPossible.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/8.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

bool equationsPossible(vector<string>& equations) {
    map<char, int> vars;
    int cur = 1;
    for (string s:equations){
        if (s[0]==s[3]&&s[1]=='!') return false;
        map<char, int>::iterator it1 = vars.find(s[0]);
        map<char, int>::iterator it2 = vars.find(s[3]);
        if (it1!=vars.end()&&it2!=vars.end()){
            if (s[1]=='!') return vars[s[0]]!=vars[s[3]];
            return vars[s[0]]==vars[s[3]];
        }
        if (it1==vars.end()) vars[s[0]]=cur++;
        if (s[1]=='!') vars[s[3]]=vars[s[0]]+1;
        else vars[s[3]]=vars[s[0]];
    }
    return true;
}

//int main(){
//    vector<string> equations = {"c==c","f!=a","f==b","b==c"};
//    cout<<equationsPossible(equations)<<endl;
//}
// 2020.06.08 第一次尝试失败
// leetcode 等式方程的可满足性
