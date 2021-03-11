//
//  orangesRotting.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/11.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    if (!grid.size()) return -1;
    int count=0;
    for (vector<int> line : grid){
        for (int num : line){
            if (num==1) count++;
        }
    }
    int cur=1;
    while (true){
        int tmp=count;
        int n=(int)grid.size(), m=(int)grid[0].size();
        for (int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]==2){
                    if (i>0&&grid[i-1][j]){
                        grid[i-1][j]=2;
                        count--;
                    }
                    if (j>0&&grid[i][j-1]) {
                        grid[i][j-1]=2;
                        count--;
                    }
                    if (i+1<n&&grid[i+1][j]) {
                        grid[i+1][j]=2;
                        count--;
                    }
                    if (j+1<m&&grid[i][j+1]) {
                        grid[i][j+1]=2;
                        count--;
                    }
                }
            }
        }
        if (count==tmp) return -1;
        if (!count) break;
        cur++;
    }
    return cur;
}

//int main(){
//    vector<vector<int>> src{{2,1,1},{1,1,0},{0,1,1}};
//    cout<<orangesRotting(src)<<endl;
//} // ? 尝试中，暂时不知道怎么做
