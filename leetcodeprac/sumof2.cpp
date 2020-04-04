#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int,int> m;
    for(int i=0;i<nums.size();i++){
        int diff=target-nums[i];
        if(m.count(diff))
            return {m[diff],i};
        m[nums[i]]=i;
    }
    return {-1,-1};
}

//int main(){
//    vector<int> src={2,7,11,15};
//    int tar=9;
//    src=twoSum(src, tar);
//    cout<<src[0]<<endl<<src[1]<<endl;
//}
