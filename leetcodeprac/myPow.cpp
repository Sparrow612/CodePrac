//
//  myPow.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/11.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

double quickPow(double x, long long n){
    if (n==0) return 1;
    double y=quickPow(x, n/2);
    return n%2?y*y*x:y*y;
}

double myPow(double x, int n) {
    long long N=n;
    return N>=0?quickPow(x, N):1.0/quickPow(x, -N);
}

//int main(){
//    cout<<myPow(2, 3)<<endl;
//}
// 快速幂算法
