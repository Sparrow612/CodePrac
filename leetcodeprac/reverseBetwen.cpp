// Leetcode 92. 翻转链表
// 经典的反转链表题，细节很多，没事多练练
// 写这种题目最后打草稿，防止自己乱掉


#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left >= right)
        return head;
    ListNode *mummy = new ListNode();
    mummy->next = head;
    ListNode *ptr = mummy, *pre = mummy, *post;

    for (int i = 1; i <= right; i++)
    {
        ptr = ptr->next;
        if (i == left - 1)
        {
            pre = ptr;
        }
    }
    post = ptr->next;
    ListNode *curr = pre->next, *last = post;
    pre->next = ptr;
    while (curr != post)
    {
        ListNode *tmp = curr->next;
        curr->next = last;
        last = curr;
        curr = tmp;
    }
    return mummy->next;
}