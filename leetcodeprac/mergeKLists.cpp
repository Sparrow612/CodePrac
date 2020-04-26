//
//  mergeKLists.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/4/26.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
    if (!a || !b) return a ? a : b;
    ListNode head, *tail=&head, *aPtr=a, *bPtr=b;
    while (aPtr&&bPtr){
        if (aPtr->val < bPtr->val){
            tail->next=aPtr;
            aPtr=aPtr->next;
        }else{
            tail->next=bPtr;
            bPtr=bPtr->next;
        }
        tail=tail->next;
    }
    tail->next=aPtr?aPtr:bPtr;
    return head.next;
} // the tool function

ListNode* merge(vector<ListNode*>& lists, int l, int r){
    if (l==r) return lists[l];
    if (l>r) return nullptr;
    int mid=(l+r)>>1;
    return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
}// the recursion function

ListNode* mergeKLists(vector<ListNode*>& lists){
    return merge(lists, 0, (int)lists.size()-1);
}// the driven function

//int main(){
//
//}

// 这道题写的我自己很不满意 写代码手生了 而且看答案了 2020.04.26
