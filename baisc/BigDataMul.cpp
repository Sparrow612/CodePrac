//
//  BigDataMul.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/9/29.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>

using namespace std;

extern const int MAX_LEN = 22; // 10的20次方，再加上一个符号位
const int MAX_LEN_OF_RES = 42; // 10的40次方

void multiply(short * factor_1, short * factor_2, short * res){
    
    short advance[MAX_LEN_OF_RES] = {};  // 存放中间结果的数组
    res[MAX_LEN_OF_RES-1] = factor_1[MAX_LEN-1]==factor_2[MAX_LEN-1]?0:1; // 首先确定乘法的符号
    
    int start = 0;
    for (int i = 0;i<MAX_LEN-1;i++){
        for (int j = 0;j<MAX_LEN-1;j++){
            advance[j + start] += factor_1[j]*factor_2[i];
        }
        start++;
    }
    
    for (int k = 0;k<MAX_LEN_OF_RES-2;k++){
        short upload =advance[k] / 10;
        advance[k] = advance[k] % 10;
        advance[k+1] += upload;
    } // 处理进位
    
    for(int k = 0;k<MAX_LEN_OF_RES-1;k++){
        res[k] = advance[k];
    } // 赋值
    
}

void push(char * src, short * des){
    int r = 0;
    while (src[r]){
        r++;
    }
    r--; // 右界
    int l = 0;
    if (src[0] == '-'){
        des[MAX_LEN-1] = 1;
        l = 1;
    } // 左界
    // 确定数的左右界，输入数组
    int num = r-l+1;
    for (int i=0;i<num;i++){
        des[i] = src[r--] - '0';
    }
}

//int main(){
//    char a[MAX_LEN], b[MAX_LEN];  // 两个因数
//    short factor_1[MAX_LEN] = {}, factor_2[MAX_LEN] ={};
//    cin>>a>>b;
//    push(a, factor_1);
//    push(b, factor_2);
//    short res[MAX_LEN_OF_RES] = {};
//    multiply(factor_1, factor_2, res);
//    
//    if (res[MAX_LEN_OF_RES-1]) cout<<'-';
//    int pos = MAX_LEN_OF_RES - 2;
//    while (!res[pos]) {
//        pos--;
//    }
//    for (int i=pos;i>=0;i--){
//        cout<<res[i];
//    }
//    cout<<endl;
//}
