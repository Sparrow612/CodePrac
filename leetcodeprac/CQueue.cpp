//
//  CQueue.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/9.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

class CQueue {
    stack<int> pre;
    stack<int> post;
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        pre.push(value);
    }
    
    int deleteHead() {
        if (post.empty()){
            while(!pre.empty()){
                post.push(pre.top());
                pre.pop();
            }
        }
        if (post.empty()) return -1;
        int res = post.top();
        post.pop();
        return res;
    }
};

//int main(){
//    CQueue* q = new CQueue;
//    cout<<q->deleteHead()<<endl;
//    q->appendTail(5);
//    q->appendTail(2);
//    cout<<q->deleteHead()<<endl;
//    cout<<q->deleteHead()<<endl;
//}

// 题目不难
