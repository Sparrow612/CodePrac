//
//  findMedianSortedArrays.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/1.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m=(int)nums1.size(), n=(int)nums2.size();
    if (n<m){
        swap(nums1, nums2);
        swap(n, m);
    }
    int left=0, right=m;
    while (left<=right){
        int i=(left+right)/2, j=(m+n+1)/2-i;
        if (i<right && nums2[j-1]>nums1[i]) left=i+1;
        else if (i>left && nums1[i-1]>nums2[j]) right=i-1;
        else {
            int maxleft;
            if (i==0) maxleft=nums2[j-1];
            else if (j==0) maxleft=nums1[i-1];
            else maxleft=max(nums1[i-1], nums2[j-1]);
            if ((m+n)%2) return maxleft;
            int minright;
            if (i==m) minright=nums2[j];
            else if (j==n) minright=nums1[i];
            else minright=min(nums1[i], nums2[j]);
            return (maxleft+minright)/2.0;
        }
    }
    return 0.0;
}

//int main(){
//    vector<int> nums1={1,2};
//    vector<int> nums2={3,4};
//    cout<<findMedianSortedArrays(nums1, nums2)<<endl;
//}

// 这道题非常难（难理解算法）
