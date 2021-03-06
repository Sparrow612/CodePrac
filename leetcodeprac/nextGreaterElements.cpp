//
//  nextGreaterElements.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/6.
//  Copyright © 2021 程荣鑫. All rights reserved.

// Leetcode 503. 下一个更大元素
// 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。

#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> idxs;
    for (int i=0;i<2*n-1;i++){
        while (!idxs.empty() && nums[i%n] > nums[idxs.top()]){
            res[idxs.top()] = nums[i%n];
            idxs.pop();
        }
        idxs.push(i%n);
    }
    return res;
}

//int main(){
//    vector<int> nums{1,2,1};
//    vector<int> res = nextGreaterElements(nums);
//    for (int i=0;i<res.size();i++){
//        cout<<res[i]<<endl;
//    }
//}
