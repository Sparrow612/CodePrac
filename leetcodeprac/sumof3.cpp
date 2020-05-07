//
//  sumof3.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/10.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int end=(int)nums.size();
    for (int i=0;i<end-2;i++){
        if (i&&nums[i-1]==nums[i]) continue; // 确保不重复
        int l=i+1,r=end-1;
        while (l<r){
            int sum=nums[i]+nums[l]+nums[r];
            if (!sum){
                vector<int> tmp={nums[i],nums[l],nums[r]};
                res.push_back(tmp);
                while (l<r&&nums[l+1]==nums[l])
                    l++;//确保所指的数真的改变了，下同
                while (l<r&&nums[r-1]==nums[r])
                    r--;
                l++;
                r--;
            }else if (sum<0) {
                while (l<r&&nums[l+1]==nums[l])
                    l++;
                l++;
            }
            else{
                while (l<r&&nums[r-1]==nums[r])
                    r--;
                r--;
            }
        }
    }
    return res;
}


//int main (){
//    vector<int> src={-1, 0, 1, 2, -1, -4};
//    vector<vector<int>> res=threeSum(src);
//    for (vector<int> t:res){
//        for (int n:t)
//            cout<<n<<" ";
//        cout<<endl;
//    }
//}

// 三数之和 双指针法
