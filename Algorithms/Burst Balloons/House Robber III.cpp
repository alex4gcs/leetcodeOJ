/**
 * 原题链接：https://leetcode.com/problems/kth-smallest-element-in-a-bst/ 
 * 二叉查找数的中序遍历是有序的，所以只要按照中序遍历来进行计数，
 * 当计数到k的时候，输出当前的值就可以了。 
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
