//
//  shortestPalindrome.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/10.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string shortestPalindrome(string s) {
    int n=(int)s.size();
    string rev(s);
    reverse(rev.begin(), rev.end());
    for (int i=0;i<n;i++){
        if (s.substr(0,n-i)==rev.substr(i))
            return rev.substr(0,i)+rev.substr(i);//找到最长的回文子串
    }
    return "";
}

int main(){
    string src="aacaaa";
    cout<<shortestPalindrome(src)<<endl;
}

//最简单直白的暴力求解
