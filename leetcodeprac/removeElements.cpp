//
//  removeElements.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/10.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
    int cur=0;
    for (int n:nums){
        if (n!=val)
            nums[cur++]=n;
    }
    return cur;
}

//int main(){
//    vector<int> nums={3,2,2,3};
//    cout<<removeElement(nums, 3)<<endl;
//}

// 基础题目没啥好说的。。。
