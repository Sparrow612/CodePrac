//
//  findSubstring.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/8.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int inline findPos(string src, string tar, int sep){
    for(int i=0;i<(int)tar.size()+1-sep;i+=sep){
        if (tar.substr(i,sep)==src) return i;
    }
    return -1;
}

bool check(vector<string>& words, string s, int n){
    for (string word : words){
        int pos=findPos(word, s, n);
        if(pos!=-1){
            s.replace(pos, n, "");
        }else return false;
    }
    return true;
}

vector<int> findSubstring(string s, vector<string>& words) {
    vector<int> res;
    if (!words.size()) return res;
    int m=(int)words[0].size();
    int n = (int)words.size()*m;
    for (int i=0;i<(int)s.size()+1-n;i++){
        if (check(words, s.substr(i,n), m))
            res.push_back(i);
    }
    return res;
} // 这是我最开始的想法，但是遇到ababaab就会错，原理是这样的：匹配ab会把原来的字符串割裂，所以出错了
  // 所以我就简单修改了一下代码，按照固定的间隔割裂字符串，就是速度实在不敢恭维。。。

//int main(){
//    string src="ababaab";
//    vector<string> words={"ab","ba","ba"};
//    vector<int> res=findSubstring(src, words);
//    for (int n:res){
//        cout<<n<<endl;
//    }
//}

