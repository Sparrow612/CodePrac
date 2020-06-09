//
//  TripleInOne.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/9.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>

using namespace std;

class TripleInOne {
    int ptrs[3];
    int size;
    vector<int> s;
public:
    TripleInOne(int stackSize): s(vector<int>(3*stackSize)){
        size = stackSize;
        ptrs[0] = -1;
        ptrs[1] = stackSize-1;
        ptrs[2] = 2*stackSize -1;
    }
    
    void push(int stackNum, int value) {
        if (ptrs[stackNum]==(stackNum+1)*size-1) return;
        s[++ptrs[stackNum]] = value;
    }
    
    int pop(int stackNum) {
        if (ptrs[stackNum]<stackNum*size) return -1;
        return s[ptrs[stackNum]--];
    }
    
    int peek(int stackNum) {
        if (ptrs[stackNum]<stackNum*size) return -1;
        return s[ptrs[stackNum]];
    }
    
    bool isEmpty(int stackNum) {
        return (ptrs[stackNum]-stackNum*size+1)==0;
    }
};

// 非常简单的题目，认真写即可。
