//
//  MovementRangeofRobot.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/8.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int sum_up(int x,int y){
    int x1=x/10,x2=x%10;
    int y1=y/10,y2=y%10;
    return x1+x2+y1+y2;
}

int movingCount(int m, int n, int k) {
    if (!k) return 1;
    vector<vector<int> > vis(m, vector<int>(n, 0));
    int ans = 1;
    vis[0][0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i == 0 && j == 0) || sum_up(i, j) > k) continue;
            if (i - 1 >= 0)
                vis[i][j] |= vis[i - 1][j];
            if (j - 1 >= 0)
                vis[i][j] |= vis[i][j - 1];
            ans += vis[i][j];
        }
    }
    return ans;
}

//int main(){
//    cout<<movingCount(16,8,4)<<endl;
//}
// 动态规划题

