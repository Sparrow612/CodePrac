//
//  convertZ.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/2.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    string res;
    vector<vector<char>> src(numRows);
    int cur=0, adder=(numRows==1)?0:1;
    for (char c:s){
        src[cur].push_back(c);
        cur+=adder;
        if (adder){
            if (cur==numRows-1) adder=-1;
            if (cur==0) adder=1;
        }
    }
    for (vector<char> line:src){
        for (char c:line) res += c;
    }
    return res;
}

//int main(){
//    string src="AB";
//    cout<<convert(src, 1)<<endl;
//}

// Z字型翻转题目
