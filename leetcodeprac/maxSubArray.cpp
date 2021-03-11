//
//  maxSubArray.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/3.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int maxSubArray(vector<int>& nums, int left, int right){
    if (left>=right) return nums[left];
    int mid=(left+right)/2;
    int maxleft=maxSubArray(nums, left, mid-1);
    int maxright=maxSubArray(nums, mid+1, right);
    int maxleftside=0, maxrightside=0, lefttmp=0, righttmp=0;
    for (int l=mid-1;l>=left;l--){
        lefttmp+=nums[l];
        maxleftside=max(maxleftside,lefttmp);
    }
    for (int r=mid+1;r<=right;r++){
        righttmp+=nums[r];
        maxrightside=max(maxrightside,righttmp);
    }
    int maxmid=nums[mid]+maxleftside+maxrightside;
    return max(max(maxleft, maxright),maxmid);
}

int maxSubArray(vector<int>& nums) {
    return maxSubArray(nums, 0, (int)nums.size()-1);
}

//int main(){
//    vector<int> nums={8,-19,5,-4,20};
//    cout<<maxSubArray(nums)<<endl;
//}
