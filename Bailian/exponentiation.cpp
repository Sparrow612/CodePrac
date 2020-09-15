//
//  exponentiation.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/9/15.
//  Copyright © 2020 程荣鑫. All rights reserved.
//
#include <iostream>
#include <string>

using namespace std;

const int MAX_VALUE = 160;
const int INPUT_SIZE = 6;

void multiple(short * res, short * factor, int exp){

    for (int i=0;i<exp;i++){
        
        int start = 0;
        
        short mid_res[MAX_VALUE] = {};
        
        for (int j = 0;j<INPUT_SIZE-1;j++){
            
            for (int k = 0;k<MAX_VALUE - start;k++){
                mid_res[k + start] += res[k]*factor[j];
            }
            
            start++;
        }
        
        for (int k = 0;k<MAX_VALUE-1;k++){
            short up = mid_res[k] / 10;
            mid_res[k] = mid_res[k] % 10;
            mid_res[k+1] += up;
        } // 处理进位
        
        for(int k = 0;k<MAX_VALUE;k++){
            res[k] = mid_res[k];
        }
    
    }
}

void print(short * res, int point){
    string result = "";
    int start = 0, end = MAX_VALUE - 1;
    
    while (res[start] == 0 and start<point)
        start++;
    
    while (res[end] == 0 and end >= point) {
        end--;
    }
    
    for (int i=start;i<=end;i++){
        if (i == point and start!=point) result = '.'+result;
        result = to_string(res[i]) + result;
    }
    
    if (end < point)
        result = '.'+result;
    
    cout<<result<<endl;
}

int main(){
    
    string base;
    int exp;
    
    while (cin>>base>>exp){
        short result[MAX_VALUE] = {}, factor[MAX_VALUE] = {}; //初始化为0
        int point = (int)base.find('.');
        if (point != string::npos)
            point = (5-point)*exp;  // 求幂最后的点位
        else point = 0;
        
        int cur = INPUT_SIZE -1;
        
        for (int i = 0;i<INPUT_SIZE-1;i++){
            if (base[cur]=='.') cur--;
            result[i] = factor[i] = base[cur--] - '0'; // 装入数组
        } // 初始化完成
       
        multiple(result, factor, exp - 1); // 乘exp-1次即可
        
        print(result, point);
        
    }
}
