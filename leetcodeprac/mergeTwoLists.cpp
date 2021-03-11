//
//  mergeTwoLists.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/1.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(){}
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    ListNode head, *tail=&head, *aptr=l1, *bptr=l2;
    while (aptr&&bptr) {
        if (aptr->val<bptr->val){
            tail->next=aptr;
            aptr=aptr->next;
        }else{
            tail->next=bptr;
            bptr=bptr->next;
        }
        tail=tail->next;
    }
    tail->next=aptr?aptr:bptr;
    return head.next;
}
