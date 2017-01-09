/**
 * 原题链接：https://leetcode.com/problems/odd-even-linked-list/ 
 * 用两个指针odd和even来把原单链表的分成奇数节点链表和偶数节点链表,
 * 然后把偶数节点链表接在奇数节点列表的后面，
 * 注意偶数节点的最后next应该指向NULL。 
 * head节点作为odd的头结点，head->next作为even的头结点，
 * 然后然后从head->next开始扫描链表，依次把节点链接在odd和even的后面即可。
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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL || head->next->next == NULL) return head;
        ListNode* odd = head, *even = head->next, *next, *oddNext, *evenNext;
        bool flag = true;
        next = even->next, oddNext = odd, evenNext = even;
        while(next != NULL) {
            if(flag) {
                oddNext->next = next;
                oddNext = next;
                next = next->next;
            } else {
                evenNext->next = next;
                evenNext = next;
                next = next->next;
            }
            flag = !flag;
        }
        oddNext->next = even, evenNext->next = NULL;
        return head;
    }
};
