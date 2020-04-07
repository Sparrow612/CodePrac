//
//  permutation.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/7.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<vector<int>>& res,vector<int>& nums,int level) {
    if (level==(int)nums.size()-1){
        vector<int> tmp(nums);
        res.push_back(tmp);
        return;
    }
    for (int i=level;i<(int)nums.size(); i++) {
        swap(nums[level], nums[i]);
        permute(res, nums, level+1);
        swap(nums[level], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    permute(res, nums, 0);
    return res;
}

int main(){
    vector<int> n={1,2,3};
    vector<vector<int>> res=permute(n);
    for  (vector<int> v:res){
        for (int n:v){
            cout<<n<<" ";
        }
        cout<<endl;
    }
}
