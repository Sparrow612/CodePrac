/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    map<char, int> m {{'I',1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
public:
    int romanToInt(string s) {
        int sum = 0;
        for (int i=0;i<s.length();i++){
            char c = s[i];
            switch (c){
                case 'I':
                    if (s[i+1] == 'V' || s[i+1] == 'X'){
                        sum += m[s[i+1]] -m[c];
                        i++;
                    }else{
                        sum += m[c];
                    }
                    break;
                case 'X':
                    if (s[i+1] == 'L' || s[i+1] == 'C'){
                        sum += m[s[i+1]] -m[c];
                        i++;
                    }else{
                        sum += m[c];
                    }
                    break;
                case 'C':
                    if (s[i+1] == 'D' || s[i+1] == 'M'){
                        sum += m[s[i+1]] -m[c];
                        i++;
                    }else{
                        sum += m[c];
                    }
                    break;
                default:
                    sum += m[c];
            }
        }
        return sum;
    }
};
// @lc code=end

