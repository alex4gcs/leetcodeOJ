/**
 * 原题链接：https://leetcode.com/problems/binary-tree-inorder-traversal/ 
 * 递归方式：按照中序遍历的顺序来递归就可以了 
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
    void inOrder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        inOrder(root -> left, ans);
        ans.push_back(root -> val);
        inOrder(root -> right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};

/**
 * 原题链接：https://leetcode.com/problems/binary-tree-inorder-traversal/ 
 * 非递归方式：
 * 用栈（stack），中序遍历的输出依次是左子树、根节点、右子树，
 * 从根节点开始一路往左子树遍历下去，并把途中所有经过的节点入栈，
 * 然后弹出一个节点，这个节点就是当前的最左节点，
 * 输出它的值，然后把它的右子树按照一路遍历左子树的方式再入栈，一直到栈空。
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        while(root != NULL) {
            st.push(root);
            root = root -> left;
        }
        while(!st.empty()) {
            TreeNode* top = st.top();
            st.pop();
            ans.push_back(top->val);
            top = top -> right;
            while(top) {
                st.push(top);
                top = top -> left;
            }
        }
        return ans;
    }
};
