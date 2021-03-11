//
//  MinStack.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/12.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class MinStack {
private:
    int min, cur=-1;
    vector<int> s;
    vector<int> mins;
public:
    /** initialize your data structure here. */
    
    MinStack():min(INT_MAX){
        
    }
    
    void push(int x) {
        if (!s.size()||min>x) min=x;
        s.push_back(x);
        mins.push_back(min);
        cur++;
    }
    
    void pop() {
        if (s.size()){
            s.pop_back();
            mins.pop_back();
            cur--;
            if (mins.size()) min=mins[cur];
        }
    }
    
    int top() {
        if (s.size()) return s[cur];
        return NULL;
    }
    
    int getMin() {
        return mins[cur];
    }
};

//int main(){
//    MinStack* s=new MinStack;
//    s->push(-10);
//    s->push(14);
//    s->push(-20);
//    cout<<s->top()<<endl;
//    s->pop();
//    cout<<s->getMin()<<endl;
//    s->push(-10);
//}
// 题目本身不难，但需要静下心来慢慢写
