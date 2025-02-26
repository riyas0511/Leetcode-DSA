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
       vector<int> postorder;
    if (root == nullptr) return postorder;

    stack<TreeNode*> st;
    TreeNode* cur = root;
    TreeNode* lastVisited = nullptr;

    while (cur != nullptr || !st.empty()) {
        if (cur != nullptr) {
            st.push(cur);
            cur = cur->left;
        } else {
            TreeNode* temp = st.top()->right;
            if (temp == nullptr || temp == lastVisited) {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->val);
                lastVisited = temp;
            } else {
                cur = temp;
            }
        }
    }

    return postorder;
    }
};