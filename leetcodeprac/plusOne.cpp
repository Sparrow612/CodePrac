//
//  plusOne.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/6/5.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = (int)digits.size()-1;
    digits[n]++;
    while (digits[n]==10){
        digits[n]=0;
        if (n) digits[--n]++;
        else digits.insert(digits.begin(), 1);
    }
    return digits;
}

//int main(){
//    vector<int> src = {9};
//    vector<int> res = plusOne(src);
//}
