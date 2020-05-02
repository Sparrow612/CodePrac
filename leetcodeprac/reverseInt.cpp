//
//  reverseInt.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/2.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int reverse(int x) {
    string s=to_string(x);
    reverse(s.begin(), s.end());
    if (s[s.size()-1]=='-') s=s[s.size()-1]+s.substr(0,s.size()-1);
    if (s[0]=='0' && s.size()>1) s=s.substr(1,s.size()-1);
    long long res=stol(s);
    if (res>INT_MAX||res<=INT_MIN) res=0;
    return (int)res;
}

//int main(){
//    int n=1534236469;
//    cout<<reverse(n)<<endl;
//}
// 如何判断溢出？记住这个小知识
