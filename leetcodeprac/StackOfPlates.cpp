//
//  StackOfPlates.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/9.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class StackOfPlates {
    int size;
    vector<stack<int>> s;
public:
    StackOfPlates(int cap) {
        size = cap;
    }
    
    void push(int val) {
        if (!size) return;
        int n = (int)s.size();
        if (n==0||s[n-1].size()==size){
            stack<int> plates;
            plates.push(val);
            s.push_back(plates);
            return;
        }
        s[n-1].push(val);
    }
    
    int pop() {
        int n = (int)s.size();
        if(n==0||s[n-1].size()==0) return -1;
        int res = s[n-1].top();
        s[n-1].pop();
        if (s[n-1].size()==0)
            s.erase(s.end()-1);
        return res;
    }
    
    int popAt(int index) {
        if (index>=(int)s.size()||s[index].size()==0) return -1;
        int res = s[index].top();
        s[index].pop();
        if (s[index].size()==0)
            s.erase(s.begin()+index);
        return res;
    }
};
