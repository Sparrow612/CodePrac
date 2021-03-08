//
//  replaceSpace.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/8.
//  Copyright © 2021 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string replaceSpace(string s) {
    string res = "";
    for(int i=0;i<s.length();i++){
        if (s[i]!=' '){
            res+=s[i];
        }else{
            res += "%20";
        }
    }
    return res;
}
