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
    int res=1;
    bool * visiable=new bool[m*n];
    for (unsigned i=1;i<m*n;i++){
        int x=i/n,y=i%n;
        int tmp=sum_up(x, y);
        if (tmp<=k && !visiable[i]){
            res++;
            visiable[i]=true;
        }
        if (tmp<k){
            if (x+1<m){
                visiable[i+n]=true;
                res++;
            }
            if (n+1<n&&!visiable[i+1]){
                visiable[i+1]=true;
                res++;
            }
        }
    }
    delete[] visiable;
    return res;
}

//int main(){
//    cout<<movingCount(16,8,4)<<endl;
//}

// 一次失败的尝试。。。 2020.04.08
