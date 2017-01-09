/**
 * ԭ�����ӣ�https://leetcode.com/problems/kth-smallest-element-in-a-bst/ 
 * ������������������������ģ�����ֻҪ����������������м�����
 * ��������k��ʱ�������ǰ��ֵ�Ϳ����ˡ� 
 */
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inTrave(TreeNode* head, int& ans,int& count,int k) {
        if(head == NULL) return;
        inTrave(head->left, ans, count, k);
        count++;
        if(count == k) {
            ans = head->val;
            return;
        }
        inTrave(head->right, ans, count, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1, count = 0;
        inTrave(root, ans, count, k);
        return ans;
    }
};
