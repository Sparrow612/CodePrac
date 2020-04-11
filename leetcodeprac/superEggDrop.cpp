//
//  superEggDrop.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/11.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

map<int, int> memo;

int dp(int K, int N) {
    if (memo.find(N * 100 + K) == memo.end()) {
        int ans;
        if (N == 0) ans = 0;
        else if (K == 1) ans = N;
        else {
            int lo = 1, hi = N;
            while (lo + 1 < hi) {
                int x = (lo + hi) / 2;
                int t1 = dp(K-1, x-1);
                int t2 = dp(K, N-x);
                if (t1 < t2) lo = x;
                else if (t1 > t2) hi = x;
                else lo = hi = x;
            }
            ans = 1 + min(max(dp(K-1, lo-1), dp(K, N-lo)),
                                max(dp(K-1, hi-1), dp(K, N-hi)));
        }
        memo[N * 100 + K] = ans;
    }
    return memo[N * 100 + K];
}

int superEggDrop(int K, int N) {
    return dp(K, N);
}

int main(){
    cout<<superEggDrop(2, 6)<<endl;
}

// 这么难的题目你当然是抄的！(x
// 没事多看看 这道题目很经典的
