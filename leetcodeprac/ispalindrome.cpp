#include <string>
#include <iostream>

using namespace std;

bool isPalindrome(string src){
    if (!src.length()) return true;
    else return src[0]==src[src.length()-1] && isPalindrome(src.substr(1,src.length()-2));
}
bool isPalindrome(int x) {
    string src=to_string(x);
    return isPalindrome(src);
}

//int main(int argc, const char * argv[]) {
//    int num=-121;
//    cout<<isPalindrome(num)<<endl;
//}
