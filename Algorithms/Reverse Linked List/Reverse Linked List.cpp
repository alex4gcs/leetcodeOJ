/**
 * 原题链接：https://leetcode.com/problems/reverse-linked-list/ 
 * 从头到尾扫描单链表，然后每次摘下一个节点，让其指向前面一个节点。
 * 需要一个root指针指向当前已经反转的部分链表的当前头结点,
 * 一个pre指针指向下一个需要反转的节点。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* root = head, *pre = head -> next;
        head = head -> next;
        root -> next = NULL;
        while(pre) {
            head = head -> next;
            pre -> next = root;
            root = pre;
            pre = head;
        }
        return root;
    }
};
