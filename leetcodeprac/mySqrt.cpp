//
//  mySqrt.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/9.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

int mySqrt(int x) {
    int l=0, r=x, ans=0;
    while (l<=r){
        int mid=(l+r)/2;
        if ((long long)mid*mid<=x){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ans;
} // 二分查找

//int main(){
//    int a=8;
//    cout<<mySqrt(a)<<endl;
//}
