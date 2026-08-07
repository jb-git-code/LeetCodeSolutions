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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        solve(root , res);
        return res;
    }

    void solve(TreeNode* node , vector<int> &res){
        // if(root == NULL) return ;
        // res.push_back(root -> val);
        // solve(root -> left , res);
        // solve(root -> right ,res);
        // return ;
        if(node == nullptr) {
            return;
        }
        stack<TreeNode*> st;
        st.push(node);
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            res.push_back(temp -> val);
            if(temp -> right){
                st.push(temp -> right);
            }
            if(temp -> left) {
                st.push(temp -> left);
            }
        }
    }
};