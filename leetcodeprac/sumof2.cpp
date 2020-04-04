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

