//
//  myAtoi.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/2.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int myAtoi(string str) {
    long long res=0;
    bool hasStart=false;
    bool ispositive=false;
    bool isnegative=false;
    int cur=0;
    for (char c:str){
        if (c!=' ') break;
        if (c==' ') cur++;
    }
    for (int i=cur;i<str.size();i++){
        char c=str[i];
        if (hasStart && !isdigit(c)) break;
        if (c==' ') break;
        if (c=='+') {
            if (isnegative||ispositive) break;
            ispositive=true;
            continue;
        }
        if (c=='-') {
            if (ispositive||isnegative) break;
            isnegative=true;
            continue;
        }
        if (!isdigit(c)) break;
        // 以下是转换逻辑
        
        if (!hasStart) hasStart=true;
        if (res>INT_MAX) {
            res=INT_MAX;
            break;
        }
        if (res<INT_MIN) {
            res=INT_MIN;
            break;
        }
        if (isnegative) res=res*10-int(c-'0');
        else res = res*10+int(c-'0');
    }
    if (res>INT_MAX) return INT_MAX;
    if (res<INT_MIN) return INT_MIN;
    return (int)res;
}
//int main(){
//    string str="0-1";
//    cout<<myAtoi(str)<<endl;
//}

// 请铭记这道题，别忘了你前前后后修改了多少次
