//
//  strStr.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/9/6.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    if (haystack.size()<needle.size()) return -1;
    for (int i=0;i<=haystack.size()-needle.size();i++){
        int index1 = i, index2 = 0;
        while (haystack[index1]&&haystack[index1] == needle[index2]){
            index1 ++;
            index2 ++;
        }
        if (index2==needle.size())
            return i;
    }
    return -1;
}

//int main(){
//    cout<<strStr("hello", "ll")<<endl;
//}
