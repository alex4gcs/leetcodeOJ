/**
 * ԭ�����ӣ�https://leetcode.com/problems/odd-even-linked-list/ 
 * ������ָ��odd��even����ԭ������ķֳ������ڵ������ż���ڵ�����,
 * Ȼ���ż���ڵ�������������ڵ��б�ĺ��棬
 * ע��ż���ڵ�����nextӦ��ָ��NULL�� 
 * head�ڵ���Ϊodd��ͷ��㣬head->next��Ϊeven��ͷ��㣬
 * Ȼ��Ȼ���head->next��ʼɨ���������ΰѽڵ�������odd��even�ĺ��漴�ɡ�
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
