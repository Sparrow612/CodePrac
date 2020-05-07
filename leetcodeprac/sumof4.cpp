//
//  sumof4.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/7.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for(int a=0;a<(int)nums.size()-3;a++){
        if (a>0 && nums[a]==nums[a-1]) continue;
        for (int b=a+1;b<(int)nums.size()-2;b++){
            if (b>a+1 && nums[b]==nums[b-1]) continue;
            int tmp1=nums[a]+nums[b];
            int c=b+1, d=(int)nums.size()-1;
            while (c<d){
                int tmp2=tmp1+nums[c]+nums[d];
                if (tmp2<target){
                    while (c<d&&nums[c+1]==nums[c]) c++;
                    c++;
                }else if (tmp2>target){
                    while (c<d&&nums[d-1]==nums[d]) d--;
                    d--;
                }else{
                    res.push_back({nums[a],nums[b],nums[c],nums[d]});
                    while (c<d&&nums[c+1]==nums[c]) c++;
                    while (c<d&&nums[d-1]==nums[d]) d--;
                    c++;
                    d--;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> src={};
    vector<vector<int>> res=fourSum(src, 0);
    for (vector<int> item : res){
        for (int num : item){
            cout<<num<<' ';
        }
        cout<<endl;
    }
}
