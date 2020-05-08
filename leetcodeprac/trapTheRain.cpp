//
//  trapTheRain.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/7.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int trap(vector<int>& height) {
    int l=0, r=(int)height.size()-1, res=0;
    int leftmax=0, rightmax=0;
    while (l<r){
        if (height[l]<=height[r]){
            if (height[l]>leftmax) leftmax=height[l];
            else res+=leftmax-height[l];
            l++;
        }else{
            if (height[r]>rightmax) rightmax=height[r];
            else res+=rightmax-height[r];
            r--;
        }
    }
    return res;
} // 双指针

//int main(){
//    vector<int> src={0,1,0,2,1,0,1,3,2,1,2,1};
//    cout<<trap(src)<<endl;
//}
