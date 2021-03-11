//
//  SortedStack.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/6.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

class SortedStack {
private:
    stack<int> s;
public:
    SortedStack() {}
    
    void push(int val) {
        stack<int> temp;
        while (!s.empty()){
            if (s.top()<val){
                temp.push(s.top());
                s.pop();
            } else break;
        }
        s.push(val);
        while (!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
    
    void pop() {
        if (!s.empty())
            s.pop();
    }
    
    int peek() {
        if(s.empty()) return -1;
        return s.top();
    }
    
    bool isEmpty() {
        return s.empty();
    }
};
