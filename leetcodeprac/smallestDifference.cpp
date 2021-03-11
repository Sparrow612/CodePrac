//
//  smallestDifference.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/12.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int smallestDifference(vector<int>& a, vector<int>& b) {
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i=0, j=0;
    int n=(int)a.size(), m=(int)b.size();
    long long diff=INT_MAX;
    while (i<n&&j<m){
        long long tmp=a[i]-b[j];
        diff=min(diff, abs(tmp));
        if (a[i]>b[j]) j++;
        else i++;
    }
    return (int)diff;
}

//int main(){
//    vector<int> a={-2147483648,1};
//    vector<int> b={2147483647,0};
//    cout<<smallestDifference(a, b)<<endl;
//}
