//
//  longestPalindrome.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/8.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    int start=0,length=1;
    vector<vector<int>> dp(s.length(),vector<int>(s.length(),0));
    int n=(int)s.size();
    for (int i=0;i<n;i++){
        dp[i][i]=1;
        if (i<n-1&&s[i]==s[i+1]){
            dp[i][i+1]=1;
            start=i;
            length=2;
        }
    }//init
    for (int len=2;len<n;len++){
        for (int left=0;left<n-len;left++){
            if (s[left]==s[left+len]&&dp[left+1][left+len-1]){
                dp[left][left+len]=1;
                start=left;
                length=len+1;
            }
        }
    }
    return s.substr(start,length);
}

//int main(){
//    string src="babad";
//    cout<<longestPalindrome(src)<<endl;
//}
//
//代码逻辑的问题不大，但是算法复杂度有待优化 2020.04.08
//优化原来的超时代码 2020.04.10


