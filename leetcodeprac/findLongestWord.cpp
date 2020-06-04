//
//  findLongestWord.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/12.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

bool cmp(string a, string b){
    if (a.size()==b.size())
        return a<b;
    return a.size()>b.size();
}

string findLongestWord(string s, vector<string>& d) {
    sort(d.begin(), d.end(), cmp);
    int n=(int)s.size();
    for (string t : d){
        int m=(int)t.size();
        int i=0, j=0;
        while (i<n&&j<m){
            if (s[i]==t[j]) j++;
            i++;
        }
        if (j==m) return t;
    }
    return "";
}

//int main(){
//    vector<string> d={"ale","apple","monkey","plea"};
//    string s="abpcplea";
//    cout<<findLongestWord(s, d)<<endl;
//}
// 朴素的双指针解法
