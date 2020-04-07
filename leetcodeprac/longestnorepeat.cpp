#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int in(string s, char tar){
    for(int i=0;i<s.length();i++){
        if (s[i]==tar)
            return i+1;
    }
    return 0;
}

int lengthOfLongestSubstring(string s) {
    if (s=="") return 0;
    int res=1;
    string * ptr=new string[s.length()];
    ptr[0]=s[0];
    for (int i=1;i<s.length();i++){
        int index=in(ptr[i-1],s[i]);
        if (index)
            ptr[i]=ptr[i-1].substr(index,ptr[i-1].length()-index)+s[i];
        else
            ptr[i]=ptr[i-1]+s[i];
        int l=int(ptr[i].length());
        res=res>l?res:l;
    }
    return res;
}

//int main(){
//    cout<<lengthOfLongestSubstring("dvdf")<<endl;
//}
//这道题有很大的优化空间
