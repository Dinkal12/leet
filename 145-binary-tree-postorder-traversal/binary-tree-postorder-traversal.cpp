/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> result;
        if (!root) return result;

        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;

        while (current || !st.empty()) {
            while (current) {
                st.push(current);
                current = current->left;
            }

            TreeNode* node = st.top();

            if (node->right && lastVisited != node->right) {
                current = node->right;
            } else {
                result.push_back(node->val);
                lastVisited = node;
                st.pop();
            }
        }

        return result; 
    }
};