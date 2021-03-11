//
//  findKthLargest.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/5.
//  Copyright © 2021 程荣鑫. All rights reserved.
//

// Leetcode 215. 数组中的第K大元素
// 思路：小根堆

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void shift_up(vector<int>& heap, int idx){
    int father;
    while ((idx-1)/2>=0 && heap[father=(idx-1)/2]>heap[idx]){
        int temp = heap[idx];
        heap[idx] = heap[father];
        heap[father] = temp;
        idx = father;
    }
}

void shift_down(vector<int>& heap, int idx, int k){
    while (1){
        int l = 2*idx+1, r = 2*idx+2, t = idx;
        if (l<k && heap[l]<heap[t]) t = l;
        if (r<k && heap[r]<heap[t]) t = r;
        
        if (idx == t) break; //
        else{
            int temp = heap[t];
            heap[t] = heap[idx];
            heap[idx] = temp;
        }
        idx = t;
    }
}

int findKthLargest(vector<int>& nums, int k) {
    vector<int> heap(k);
    int cur = 0;
    for (int i=0;i<nums.size();i++){
        if (cur<k){
            heap[cur]=nums[i];
            shift_up(heap,cur++);
        }
        else if(nums[i]>heap[0]){
            heap[0] = nums[i];
            shift_down(heap, 0, k);
        }
    }
    return heap[0];
}

//int main(){
//    vector<int> nums{3,2,3,1,2,4,5,5,6};
//    int r = findKthLargest(nums, 4);
//    cout<<r<<endl;
//}


