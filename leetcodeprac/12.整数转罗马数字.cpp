/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;
class Solution{
public:
string intToRoman(int num) {
    vector<string> thousands({"", "M", "MM", "MMM"});
    vector<string> hundreds({"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"});
    vector<string> tens({"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"});
    vector<string> ones({"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"});
    string result = thousands[num/1000];
    num %= 1000;
    result += hundreds[num/100];
    num %= 100;
    result += tens[num/10];
    num %= 10;
    result += ones[num];
    return result;
}
};

// @lc code=end

