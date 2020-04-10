//
//  reverseWords.cpp
//  leetcodeprac
//
//  Created by 程荣鑫 on 2020/4/10.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string reverseWords(string s) {
    reverse(s.begin(), s.end());
    int idx=0;
    int n=(int)s.size();
    for (int start=0;start<n;start++){
        if (s[start]!=' '){
            if (idx) s[idx++]=' ';//每个单词末尾的一个空格
            int end=start;
            while (end<n&&s[end]!=' ')
                s[idx++]=s[end++];
            reverse(s.begin()+idx-(end-start), s.begin()+idx);//颠倒每个单词
            start=end;
        }
    }
    s.erase(s.begin()+idx,s.end());
    return s;
}

//int main(){
//    string src="  hello world!  ";
//    cout<<reverseWords(src)<<endl;
//}

// 考验C++基本功的题目C++ 建议没事多拿出来写几遍
