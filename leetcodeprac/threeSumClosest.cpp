//
//  threeSumClosest.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/8.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int res=nums[0]+nums[1]+nums[(int)nums.size()-1];
    sort(nums.begin(), nums.end());
    for (int a=0;a<(int)nums.size()-2;a++){
        if (a>0&&nums[a-1]==nums[a]) continue;
        int b=a+1, c=(int)nums.size()-1;
        while (b<c){
            int tmp=nums[a]+nums[b]+nums[c];
            if (abs(res-target)>abs(tmp-target)) res=tmp;
            if (tmp<target){
                while (b<c&&nums[b+1]==nums[b]) b++;
                b++;
            }else if (tmp>target){
                while (b<c&&nums[c-1]==nums[c]) c--;
                c--;
            }else return target;
        }
    }
    return res;
}

//int main(){
//    vector<int> nums={1,1,1,1};
//    int target=-100;
//    cout<<threeSumClosest(nums, target)<<endl;
//}
