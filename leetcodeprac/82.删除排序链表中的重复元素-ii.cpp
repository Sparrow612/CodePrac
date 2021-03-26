/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    // void deleteNodes(ListNode* left, int n){
    //     for (int i=0;i<n;i++){
    //         left->next = left->next->next;
    //     }
    // }
    // ListNode* deleteDuplicates(ListNode* head) {
    //     map<int, int> table;
    //     ListNode* cur = head;
    //     while (cur){
    //         int v = cur->val;
    //         if (table.find(v)!=table.end()){
    //             table[v]++;
    //         }
    //         else{
    //             table[v] = 1;
    //         }
    //         cur=cur->next;
    //     }
    //     ListNode* dummy = new ListNode();
    //     dummy->next = head;
    //     cur = dummy;
    //     while (cur && cur->next){
    //         int n = table[cur->next->val];
    //         if (n>1){
    //             deleteNodes(cur, n);
    //         }else{
    //             cur = cur->next; // 删除节点后，需要停留在当前节点，判断新跟上的有无重复
    //         }
    //     }
    //     return dummy->next;
    // }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur && cur->next && cur->next->next){
            if (cur->next->val == cur->next->next->val){
                int x = cur->next->val;
                while (cur->next && cur->next->val == x){
                    cur->next = cur->next->next;
                }
            }else{
                cur = cur->next; // 需要停留在当前节点，判断新接上的节点是否为重复
            }
        }
        return dummy->next;
    }
};
// @lc code=end

