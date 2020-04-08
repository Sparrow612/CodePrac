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
    vector<vector<int>> ispalind(s.length(),vector<int>(s.length(),0));
    string res;
    for (int i=0;i<s.length();i++){
        ispalind[i][i]=1;
        if (i+1<s.length()&&s[i+1]==s[i])
            ispalind[i][i+1]=1;
    }
    for (int l=0;l<s.length();l++){
        for (int i=0;i<s.length()-l;i++){
            int j=i+l;
            if (ispalind[i][j]){
                res=s.substr(i,l+1);
                break;
            }
            if ((ispalind[i+1][j-1] && s[i]==s[j])){
                ispalind[i][j]=1;
                res=s.substr(i,l+1);
            }
        }
    }
    return res;
}

//int main(){
//    string src="cbbd";
//    cout<<longestPalindrome(src)<<endl;
//}
//
//代码逻辑的问题不大，但是算法复杂度有待优化 2020.04.08


