//
//  circularQueue.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/7.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class CircularDeque {
private:
    int cur, contain;
    vector<int> repo;
    int head, tail;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    CircularDeque(int k): repo(vector<int>(k)), cur(0), contain(k), head(1), tail(-1){}
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (cur==contain) return false;
        if (!cur) tail=0;
        head = (head-1+contain)%contain;
        repo[head] = value;
        cur++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (cur == contain)return false;
        if (!cur) head = 0;
        tail = (tail+1)%contain;
        repo[tail] = value;
        cur++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (!cur) return false;
        head = (head+1)%contain;
        cur--;
        if (!cur) {
            head=1;
            tail=-1;
        }
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (!tail) return false;
        tail = (tail-1+contain)%contain;
        cur--;
        if (!cur){
            head=1;
            tail=-1;
        }
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (cur==0) return -1;
        return repo[head];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (cur==0) return -1;
        return repo[tail];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cur==0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cur==contain;
    }
};

//int main(){
//    CircularDeque * circulardeque = new CircularDeque(4);
//    circulardeque->insertFront(9);
//    circulardeque->deleteLast();
//    cout<<circulardeque->getFront()<<endl<<circulardeque->getRear()<<endl;
//}

// 这道题很简单，也过了
// 但是有空想想看有没有更好的实现方式

