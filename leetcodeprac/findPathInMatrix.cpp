//
//  findPathInMatrix.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/8.
//  Copyright © 2021 程荣鑫. All rights reserved.
// Leetcode 剑指Offer 12. 矩阵中的路径
// 评语：dfs写的不熟练，建议多看点模版，本题就是一个不错的dfs模版

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

bool ans = false;
int m = 0, n = 0;

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index){
    if (i<0||j<0||i>=m||j>=n||board[i][j]!=word[index]) return false;
    if (index == word.size()-1) return true;
    board[i][j] = ' '; // 防止重复访问
    bool res = dfs(board, word, i+1, j, index+1) || dfs(board, word, i, j+1, index+1) || dfs(board, word, i-1, j, index+1) || dfs(board, word, i, j-1, index+1);
    board[i][j] = word[index];
    return res;
}

bool exist(vector<vector<char>>& board, string word) {
    m = board.size();
    if ( m==0 ) return false;
    n = board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if (dfs(board, word, i, j, 0)) return true;
        }
    }
    return false;
    
}

//int main(){
//    vector<vector<char>> board = {{'a','b','c','e'},
//        {'s','f','c','s'},
//        {'a','d','e','e'}};
//    string word= "bfce";
//    cout<<exist(board, word)<<endl;
//}

