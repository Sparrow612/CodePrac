//
//  LFUCache.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/28.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int key, value, freq, age;
    Node(){}
    Node (int k, int v): key(k),value(v),freq(1), age(1){}
};

class LFUCache {
private:
    int cur = 0; // 当前个数
    vector<Node> src;
    void addAge(){
        for (int i=0;i<cur;i++){
            src[i].age++;
        }
    }
    int findPageToReplace(){
        int minUse = INT_MAX;
        int index = 0;
        for (int i=0;i<cur;i++){
            if (src[i].freq<minUse){
                minUse = src[i].freq;
                index = i;
            }
        }
        for (int i=0;i<cur;i++){
            if (src[i].freq == minUse){
                if (src[i].age>src[index].age){
                    index = i;
                }
            }
        }
        return index;
    }
public:
    LFUCache(int capacity): src(capacity){}
    
    int get(int key) {
        addAge();
        for(int i=0;i<cur;i++){
            Node& n = src[i];
            if (n.key==key){
                n.freq++;
                n.age = 1;
                return n.value;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        addAge();
        for (int i=0;i<cur;i++){
            Node& n = src[i];
            if (n.key==key){
                n.value = value;
                n.freq++;
                n.age = 1;
                return;
            }
        }
        Node n(key,value);
        if (cur<(int)src.size())
            src[cur++]=n;
        else if (src.size()>0){
            src[findPageToReplace()] = n;
        }
    }
};
//int main(){
//    LFUCache * cache = new LFUCache(2);
//    cache->put(2,1);
//    cache->put(3,2);
//    cout<<cache->get(3)<<endl<<cache->get(2)<<endl;
//    cache->put(4,3);
////    cache->put(4, 1);
//    cout<<cache->get(2)<<endl;
////    cout<<cache->get(3)<<endl;
////    cout<<cache->get(4)<<endl;
//}
// 2020.5.28 第一次尝试，失败
// 2020.6.5 第二次尝试，终于成功，但是代码逻辑混乱不堪，时间复杂度较高
