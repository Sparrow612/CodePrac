//
//  BigDataAdd.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/9/29.
//  Copyright © 2020 程荣鑫. All rights reserved.
//
#include <iostream>

using namespace std;

const int LEN = 22;

void add(short * adder_1, short* adder_2, short * res){
    
    bool positive=false, negative=false;
    if(!adder_1[LEN-1]&&!adder_2[LEN-1]) positive = true;
    else if (adder_1[LEN-1]&&adder_2[LEN-1]) negative = true;
    for (int i=0;i<LEN-1;i++){
        res[i] = adder_1[i]+adder_2[i];
    }
    
    if (negative){
        for (int i=0;i<LEN-1;i++){
            res[i] = -res[i];
        }
    }// 两个负数相加
    
    if (negative || positive){
        for (int i=0;i<LEN-2;i++){
            short upload =res[i] / 10;
            res[i] = res[i] % 10;
            res[i+1] += upload;
        } // 处理进位
    } // 一正一负不需要考虑进位
    
    if (positive || negative) {
        if (negative) res[LEN-1] = 1;
        return;
    } // 对于可以直接判断正负的情况，不用下面的处理
    for (int i=0;res[LEN-1]!=1&&i<LEN-2;i++){
        int amount = 0;
        int t = 0;
        while ((t=res[i] + amount*10)<0){
            amount++;
        }
        res[i] = t;
        res[i+1] -= amount;
    } // 只有一正一负需要，这里起两个作用
    // 1. 结果为正数，这里相当于完成借位，把结果的每一位修正
    // 2. 结果为负数，将负号向前传递，直至最高位，便于下面直接判断
    
    // crx自创的退位算法，高位负数一步一步往低位退
    if (res[LEN-2] < 0){
        res[LEN-1] = 1;
        for (int i = LEN-1;i>0;i--){
            if (res[i-1]>=0){
                res[i-1] -= 10;
                res[i]++;
            }
            res[i] = -res[i];
        }
        if (res[0]==-10) {
            res[1]++;
            res[0] = 0;
        } // 消除多余的退位
        res[0] = -res[0];
    }
}

void push_into_array(char * src, short * des){
    int r = 0;
    while (src[r]){
        r++;
    }
    r--; // 右界
    int l = 0;
    if (src[0] == '-'){
        des[LEN-1] = 1;
        l = 1;
    } // 左界
    // 确定数的左右界，输入数组
    int num = r-l+1;
    for (int i=0;i<num;i++){
        des[i] = src[r--] - '0';
        if (des[LEN-1]) des[i] = -des[i];
    }
}

int main(){
    char a[LEN], b[LEN];  // 两个因数
    short factor_1[LEN] = {}, factor_2[LEN] = {};
    cin>>a>>b;
    push_into_array(a, factor_1);
    push_into_array(b, factor_2);
    short res[LEN] = {};
    add(factor_1, factor_2, res);
    if (res[LEN-1]) cout<<'-';
    int pos = LEN - 2;
    while (!res[pos]) {
        pos--;
    }
    for (int i=pos;i>=0;i--){
        cout<<res[i];
    }
    cout<<endl;
}

