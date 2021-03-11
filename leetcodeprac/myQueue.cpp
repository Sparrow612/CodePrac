//
//  myQueue.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/5.
//  Copyright © 2021 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> in;
    stack<int> out;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = NULL;
        if (out.empty()){
            while (!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        
        if (!out.empty()){
            res= out.top();
            out.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if (out.empty()){
            while (!in.empty()){
                out.push(in.top());
                in.pop();
            }
        }
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty()&&out.empty();
    }
};
