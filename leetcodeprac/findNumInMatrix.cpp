//
//  findNumInMatrix.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/8.
//  Copyright © 2021 程荣鑫. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int m,n;
    m = matrix.size();
    if (m == 0) return false;
    n = matrix[0].size();
    int r = 0, c = n-1;
    while (r<m && c >= 0){
        if (matrix[r][c] == target) return true;
        if (matrix[r][c] < target){
            r++;
        }else{
            c--;
        }
    }
    return false;
}

//int main(){
//    vector<vector<int>> t({{5,6,10,14},{6,10,13,18},{10,13,18,19}});
//}
