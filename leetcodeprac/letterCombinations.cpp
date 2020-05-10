//
//  letterCombinations.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/9.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

unordered_map<string, string> repo({
    {"2","abc"},
    {"3","def"},
    {"4","ghi"},
    {"5","jkl"},
    {"6","mno"},
    {"7","pqrs"},
    {"8","tuv"},
    {"9","wxyz"}
});


void backtrace(vector<string>& src,string before,string code){
    if (code=="") src.push_back(before);
    string head=code.substr(0,1);
    string value=repo[head];
    for (int i=0;i<(int)value.size();i++){
        backtrace(src, before+value[i], code.substr(1));
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> res;
    if (digits!="") backtrace(res,"",digits);
    return res;
}

//int main(){
//    vector<string> res=letterCombinations("23");
//    for (string s: res){
//        cout<<s<<endl;
//    }
//}

// 这道题我们采用回溯算法
// 电话号码所有可能的字母组合
