//
//  combine.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/3.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> output;
    vector<int> ini;
    for (int i=1;i<=k;i++)
        ini.push_back(i);
    ini.push_back(n+1);
    int j = 0;
    while (j<k){
        vector<int> tmp;
        for (int i=0;i<k;i++) tmp.push_back(ini[i]);
        j = 0;
        output.push_back(tmp);
        while (j<k && ini[j]+1==ini[j+1]){
            ini[j]=j+1;
            j++;
        }
        ini[j]+=1;
    }
    return output;
}

//int main(){
//    vector<vector<int>> res=combine(4,2);
//
//}

// 字典序求组合法
