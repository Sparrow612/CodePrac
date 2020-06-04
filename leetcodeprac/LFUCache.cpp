//
//  LFUCache.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/28.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node {
    int key, value;
};

class LFUCache {
private:
    int cur = 0;
    int capa;
    Node * ptr;
    Node * list;
    int find(int key){
        int i = 0;
        while (i < cur){
            if (list[i].key==key){
                if (ptr->key == key){
                    ptr = &list[(i+1)%capa];
                }
                break;
            }
            i++;
        }
        return i;
    }
public:
    LFUCache(int capacity): capa(capacity) {
        list = new Node[capacity];
        ptr = list;
    }
    
    int get(int key) {
        int i=find(key);
        if (i==cur) return -1;
        return list[i].value;
    }
    
    void put(int key, int value) {
        if (capa){
            int i =find(key);
            if (i<cur){
                list[i].value = value;
                return;
            }
            if (cur == capa){
                ptr->key = key;
                ptr->value = value;
               
            } else {
                list[cur].key=key;
                list[cur].value=value;
                cur++;
            }
        }
    }
};

