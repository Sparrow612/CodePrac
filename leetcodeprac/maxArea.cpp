//
//  maxArea.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/7.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int maxArea(vector<int>& height) {
    int ans=0;
    int left=0, right=(int)height.size()-1;
    while (left<right){
        ans=max(ans, min(height[left],height[right])*(right-left));
        if (height[left]<height[right]){ // 为什么移动较小的那个？因为移动大的那个，最小值肯定不增加，但是间隔会缩小，面积肯定会变小
            left++;
        }else{
            right--;
        }
    }
    return ans;
}

//int main(){
//    vector<int> src={1,8,6,2,5,4,8,3,7};
//    cout<<maxArea(src)<<endl;
//}

// 双指针解法

