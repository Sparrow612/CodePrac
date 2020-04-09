//
//  validbrackets.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/9.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool matched(char l,char r){
    char expect;
    switch (l) {
        case '(':
            expect=')';
            break;
        case '[':
            expect=']';
            break;
        case '{':
            expect='}';
            break;
        default:
            expect='\0';
            break;
    }
    if (r!=expect)
        return false;
    return true;
}

bool isValid(string s) {
    stack<char> t;
    for (char c:s){
        if (c=='('||c=='['||c=='{')
            t.push(c);
        else{
            if (t.empty())return false;
            if (!matched(t.top(), c))
                return false;
            t.pop();
        }
    }
    
    if (t.empty())
        return true;
    return false;
}

int main(){
    string src="]";
    cout<<isValid(src)<<endl;
}

// 栈的基本应用
