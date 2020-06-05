//
//  spiralOrder.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/5.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void spiralOrder(vector<vector<int>>& matrix, int topleft, int topright, int top,int bottom, vector<int>& output) {
    if (topleft>topright||top>bottom) return;
    for (int i=topleft;i<=topright;i++)
        output.push_back(matrix[top][i]);
    if (top<bottom){
        for (int i=top + 1;i<bottom;i++) output.push_back(matrix[i][topright]);
        for (int i=topright;i>=topleft;i--) output.push_back(matrix[bottom][i]);
        if (topleft<topright){
            for (int i=bottom-1;i>top;i--)
                output.push_back(matrix[i][topleft]);
        }
    }
    spiralOrder(matrix, topleft+1, topright-1, top+1,bottom-1, output);
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    if (!n) return vector<int>();
    int m = (int)matrix[0].size();
    vector<int> output;
    spiralOrder(matrix,0,m-1,0,n-1, output);
    return output;
}

//int main(){
//    vector<vector<int>> src({{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}});
//    vector<int> output = spiralOrder(src);
//    for (int n:output)
//        cout<<n<<endl;
//}
