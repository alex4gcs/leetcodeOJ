/**
 * ԭ�����ӣ�https://leetcode.com/problems/binary-tree-inorder-traversal/ 
 * �ݹ鷽ʽ���������������˳�����ݹ�Ϳ����� 
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
 * ԭ�����ӣ�https://leetcode.com/problems/binary-tree-inorder-traversal/ 
 * �ǵݹ鷽ʽ��
 * ��ջ��stack���������������������������������ڵ㡢��������
 * �Ӹ��ڵ㿪ʼһ·��������������ȥ������;�����о����Ľڵ���ջ��
 * Ȼ�󵯳�һ���ڵ㣬����ڵ���ǵ�ǰ������ڵ㣬
 * �������ֵ��Ȼ�����������������һ·�����������ķ�ʽ����ջ��һֱ��ջ�ա�
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
