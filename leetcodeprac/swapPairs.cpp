//
//  swapPairs.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/9.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head||!head->next) return head;
    ListNode * cur=head;
    ListNode * bef=nullptr;
    bool first=true;
    while (cur) {
        ListNode * nearby=cur->next;
        if (!nearby) break;
        cur->next=nearby->next;
        nearby->next=cur;
        if (first){
            head=nearby;
            first=false;
        }
        if (bef) bef->next=nearby;
        bef = cur;
        cur = cur->next;
    }
    return head;
}

//int main(){
//    ListNode * head=new ListNode(1);
//    ListNode * second=new ListNode(2);
//    ListNode * third=new ListNode(3);
//    ListNode * fourth=new ListNode(4);
//    head->next=second;
//    second->next=third;
//    third->next=fourth;
//    ListNode * cur=swapPairs(head);
//    while (cur) {
//        cout<<cur->val<<endl;
//        cur=cur->next;
//    }
//}
