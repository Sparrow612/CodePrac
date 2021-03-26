/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode * dummy = new ListNode(-101);
        dummy->next = head;
        ListNode* pre = dummy, *cur = head;
        while (cur){
            if (cur->val == pre->val){
                pre->next = pre->next->next;
            }else{
                pre = cur;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
// @lc code=end

