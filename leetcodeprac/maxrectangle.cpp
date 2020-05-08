//
//  maxrectangle.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/7.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//int largestRectangleArea(vector<int>& heights) {
//    int res=0;
//    stack<int> s;
//    s.push(-1);
//    for (int i=0;i<heights.size();i++){
//        while (s.top()!=-1&&heights[s.top()]>=heights[i]){
//            int h=heights[s.top()];
//            s.pop();
//            res=max(res,h*(i-1-s.top()));
//        }
//        s.push(i);
//    }
//    while (s.top()!=-1){
//        int h=heights[s.top()];
//        s.pop();
//        res=max(res,h*((int)heights.size()-1-s.top()));
//    }
//    return res;
//} // a stack solution, pass

//int largestRectangleArea(vector<int>& heights) {
//    int maxv=0;
//    for (int i=0;i<(int)heights.size();i++){
//        int minh=heights[i];
//        for (int j=i;j<(int)heights.size();j++){
//            minh=min(minh, heights[j]);
//            maxv=max((j-i+1)*minh,maxv);
//        }
//    }
//    return maxv;
//} // a normal solution, timeout!



//int main(){
//    vector<int> heights={2,1,5,6,2,3};
//    cout<<largestRectangleArea(heights)<<endl;
//}

