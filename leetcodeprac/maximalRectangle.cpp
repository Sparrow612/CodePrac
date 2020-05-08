//
//  maximalRectangle.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/8.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int calmax(vector<int>& heights){
    stack<int> src;
    src.push(-1);
    int res=0;
    for (int i=0;i<(int)heights.size();i++){
        while(src.top()!=-1&&heights[i]<=heights[src.top()]){
            int h=heights[src.top()];
            src.pop();
            res=max(res, h*(i-src.top()-1));
        }
        src.push(i);
    }
    while (src.top()!=-1) {
        int h=heights[src.top()];
        src.pop();
        res=max(res, h*((int)heights.size()-src.top()-1));
    }
    return res;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int n=(int)matrix.size();
    if (!n) return 0;
    int m=(int)matrix[0].size();
    int res=0;
    vector<int> heights(n,0);
    for (int row=0;row<n;row++){
        heights[row]=matrix[row][0]-'0';
    }
    res=max(res, calmax(heights)); // 第一列需要单独算一下别忘了
    for (int col=1;col<m;col++){
        for (int row=0;row<n;row++){
            if (matrix[row][col]=='1') heights[row]++;
            else heights[row]=0;
        }
        res=max(calmax(heights),res);
    }
    return res;
}
// 解决思路：二维矩阵逐列地转为柱状图，然后用之前求柱状图最大面积的解法来求
// 有时间研究一下另一种动态规划算法
