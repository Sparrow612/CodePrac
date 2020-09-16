//
//  telephoneNumber.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/9/16.
//  Copyright © 2020 程荣鑫. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int TEL_LEN = 7;

map<char, int> t;

vector<vector<char>> table = {
    {'A', 'B', 'C'}, {'D', 'E', 'F'},
    {'G', 'H', 'I'}, {'J', 'K', 'L'},
    {'M', 'N', 'O'}, {'P', 'R', 'S'},
    {'T', 'U', 'V'}, {'W','X','Y'}
};

int doc[10000000] = {};  // 记录每个电话号码出现的次数
vector<string> tels;  // 保存电话号码

void print(string& tel, int num){
    for (int i=0;i<TEL_LEN;i++) {
        if (i==3) cout<<'-';
        cout<<tel[i];
    }
    cout<<' ';
    cout<<num<<endl;
}

void translate(string& src) {
    string res = "";
    for (char s: src){
        if (s != '-') {
            if (s>='A' && s<='Y'){
                res += to_string(t[s]);
            }else {
                res += s;
            }
        }
    }
    int result = stoi(res);
    if (doc[result] == 0) tels.push_back(res);
    doc[result]++;
}

void buildMap(){
    for(int i=0;i<table.size();i++){
        for (char s: table[i]){
            t[s] = i+2;
        }
    }
}

int main(){
    buildMap();

    int num;
    cin>>num;
    string src;
    for (int i=0;i<num;i++){
        cin>>src;
        translate(src);
    }

    sort(tels.begin(), tels.end());

    bool flag = false;

    for (string& s: tels){
        int r = stoi(s);
        if (doc[r] > 1){
            flag = true;
            print(s, doc[r]);
        }
    }
    
    if (!flag) {
        cout<<"No duplicates."<<endl;
    }
}
