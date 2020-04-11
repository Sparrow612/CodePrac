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

//string shortestPalindrome(string s) {
//    int n=(int)s.size();
//    string rev(s);
//    reverse(rev.begin(), rev.end());
//    for (int i=0;i<n;i++){
//        if (s.substr(0,n-i)==rev.substr(i))
//            return rev.substr(0,i)+s;//找到最长的回文子串
//    }
//    return "";
//}


//上面是最简单直白的暴力求解，事实证明过不了

string shortestPalindrome(string s) {
    int n=(int)s.size();
    int i=0;
    for (int j=n-1;j>=0;j--){
        if (s[i]==s[j])
            i++;
    }
    if (i==n) return s;
    string tmp=s.substr(i);
    reverse(tmp.begin(), tmp.end());
    return tmp+shortestPalindrome(s.substr(0,i))+s.substr(i);
}


//int main(){
//    string src="aacecaaa";
//    cout<<shortestPalindrome(src)<<endl;
//}

//这里的算法是双指针+递归
