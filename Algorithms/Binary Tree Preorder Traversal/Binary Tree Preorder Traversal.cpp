/**
 * 原题链接：https://leetcode.com/problems/binary-tree-preorder-traversal/ 
 * 递归：按照二叉树先序遍历的顺序访问即可： 
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
    void preOrder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        ans.push_back(root -> val);
        preOrder(root -> left, ans);
        preOrder(root -> right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preOrder(root, ans);
        return ans;
    }
};

/**
 * 非递归方式：
 * 需要用到栈（stack）,由于栈的特性是后进显出（LIFO，Last In First Out），
 * 所以在子树压栈的时候需要先压右子树再压左子树，
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode* > st;
        if(root) st.push(root);
        while(!st.empty()) {
            TreeNode* front = st.top();
            ans.push_back(front -> val);
            st.pop();
            if(front -> right) st.push(front -> right);
            if(front -> left) st.push(front -> left);
        }
        return ans;
    }
};
