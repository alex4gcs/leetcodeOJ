/**
 * ԭ�����ӣ�https://leetcode.com/problems/reverse-linked-list/ 
 * ��ͷ��βɨ�赥����Ȼ��ÿ��ժ��һ���ڵ㣬����ָ��ǰ��һ���ڵ㡣
 * ��Ҫһ��rootָ��ָ��ǰ�Ѿ���ת�Ĳ�������ĵ�ǰͷ���,
 * һ��preָ��ָ����һ����Ҫ��ת�Ľڵ㡣
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
