//
//  subsets.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/3.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> intepret(vector<int>& num, int index, int length){
    vector<int> res;
    for (int j=0;j<length;j++){
        if (index&(1<<j)){
            res.push_back(num[j]);
        }
    }
    return res;
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    int n = (int)nums.size();
    for (int i=0;i<(1<<n);i++){
        res.push_back(intepret(nums, i, (int)nums.size()));
    }
    return res;
}

//int main(){
//    vector<int> s = {1,2,3};
//    vector<vector<int>> src = subsets(s);
//
//}
// bitmap求子集
