//
//  shipWithinDays.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/11.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int getDays(vector<int>& weights, int carry){
    int n=(int)weights.size();
    int cur=0, days=0;
    while (cur<n){
        int tmp=0;
        while (tmp<carry&&cur<n){
            tmp+=weights[cur++];
        }
        if (tmp>carry) cur--;
        days++;
    }
    return days;
}

int shipWithinDays(vector<int>& weights, int D) {
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);
    int days, mid = 0;
    while (left<right){
        mid=(left+right)/2;
        days=getDays(weights, mid);
        if (days<=D){
            right=mid;
        }else if (days>D){
            left=mid+1;
        }
    }
    return left;
} // 用二分时，想清楚什么时候是l<=r 什么时候又不是，想清楚l和r的变换条件

//int main(){
//    vector<int> weights={1,2,3,4,5,6,7,8,9,10};
//    cout<<shipWithinDays(weights, 5)<<endl;
//}
