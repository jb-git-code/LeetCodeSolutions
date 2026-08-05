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
    int height(TreeNode* node) {
        if (node == NULL)
            return 0;

        return 1 + max(height(node->left), height(node->right));
    }

    void solve(TreeNode* node, bool &ans) {
        if (node == NULL || ans == false)
            return;

        solve(node->left, ans);
        solve(node->right, ans);

        int lh = height(node->left);
        int rh = height(node->right);

        ans = (ans && abs(lh - rh) <= 1);
    }

    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root, ans);
        return ans;
    }
};