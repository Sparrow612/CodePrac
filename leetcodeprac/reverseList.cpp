//
//  reverseList.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2021/3/5.
//  Copyright © 2021 程荣鑫. All rights reserved.
//

#include <stdio.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr, *curr = head, *nxt;
        while (curr != nullptr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
