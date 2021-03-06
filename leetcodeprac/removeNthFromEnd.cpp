//
//  removeNthFromEnd.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/28.
//  Copyright © 2020 程荣鑫. All rights reserved.
//  Leetcode 19. 删除链表的倒数第N个节点

#include <stdio.h>
#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head, *slow = head, *prev = nullptr;
        int cur = 1;
        while (cur< n && fast->next != nullptr){
            fast = fast->next;
            cur++;
        }
        if (cur < n) {
            return head;
        }
        while (fast->next!=nullptr){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
    
        // 删除head时需要移动head
        if (slow == head){
            head = head->next;
        }else{
            prev->next = slow->next;
        }
        
        return head;
    }

//int main() {
//    char * a="abc";
//    cout<<a[0]<<endl;
//}
