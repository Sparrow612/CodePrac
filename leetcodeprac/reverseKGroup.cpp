//
//  reverseKGroup.cpp
//  CodePrac
//
//  Created by 程荣鑫 on 2020/5/10.
//  Copyright © 2020 程荣鑫. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    stack<ListNode*> s;
    ListNode *cur=head, *dummy=new ListNode(0), *ptr=dummy;
    while (cur){
        ListNode * tmp=cur;
        int count=0;
        while (tmp&&count!=k){
            count++;
            tmp=tmp->next;
        }
        if (count==k){
            for (int i=0;i<k&&cur;i++){
                s.push(cur);
                cur=cur->next;
            }
            while (!s.empty()){
                ptr->next=s.top();
                s.pop();
                ptr=ptr->next;
                ptr->next=nullptr;
            }
        }else { // 剩下来的不足k个, 那就接上，然后退出循环
            ptr->next=cur;
            break;
        }
    }
    return dummy->next;
}

//int main(){
//    ListNode * first=new ListNode(1);
//    ListNode * second=new ListNode(2);
//    ListNode * third=new ListNode(3);
//    ListNode * fourth=new ListNode(4);
//    ListNode * fifth=new ListNode(5);
//    first->next=second;
//    second->next=third;
//    third->next=fourth;
//    fourth->next=fifth;
//    ListNode * cur=reverseKGroup(first, 3);
//    while (cur) {
//        cout<<cur->val<<endl;
//        cur=cur->next;
//    }
//}

// 三种思路：1. 栈 2. 尾插法 3. 递归
// 尾插法说明：1->2->3=> 2->3->1 => 3->2->1
