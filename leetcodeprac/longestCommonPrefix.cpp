//
//  longestCommonPrefix.cpp
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

string longestCommonPrefix(vector<string>& strs) {
    if (!strs.size()) return "";
    sort(strs.begin(), strs.end());
    int n=(int)strs[0].size();
    for (int i=0;i<n;i++){
        char c=strs[0][i];
        for (int j=1;j<(int)strs.size();j++){
            if (strs[j][i]!=c) return strs[0].substr(0,i);
        }
    }
    return strs[0];
}


