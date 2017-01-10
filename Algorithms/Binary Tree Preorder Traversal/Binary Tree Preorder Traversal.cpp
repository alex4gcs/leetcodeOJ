/**
 * ԭ�����ӣ�https://leetcode.com/problems/binary-tree-preorder-traversal/ 
 * �ݹ飺���ն��������������˳����ʼ��ɣ� 
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
 * �ǵݹ鷽ʽ��
 * ��Ҫ�õ�ջ��stack��,����ջ�������Ǻ���Գ���LIFO��Last In First Out����
 * ����������ѹջ��ʱ����Ҫ��ѹ��������ѹ��������
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
