//
//  DinnerPlates.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/9.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class DinnerPlates {
private:
    int capa;
    vector<stack<int>> plates;
public:
    DinnerPlates(int capacity): capa(capacity) {
        
    }
    
    void push(int val) {
        if (!capa) return;
        for (stack<int>& s: plates){
            if (s.size()<capa){
                s.push(val);
                return;
            }
        }
        stack<int> s;
        s.push(val);
        plates.push_back(s);
    }
    
    int pop() {
        int n = (int)plates.size();
        if (!n) return -1;
        for (int i =n-1;i>=0;i--){
            if (!plates[i].empty()){
                int res = plates[i].top();
                plates[i].pop();
                return res;
            }
        }
        return -1;
    }
    
    int popAtStack(int index) {
        if ((int)plates.size()<=index) return -1;
        if (plates[index].empty()) return -1;
        int res = plates[index].top();
        plates[index].pop();
        return res;
    }
};

//int main(){
//    DinnerPlates * d = new DinnerPlates(1);
//    d->push(1);
//    d->push(2);
//    cout<<d->popAtStack(0)<<endl;
//}

// 2020.06.09 第一次尝试，超时
