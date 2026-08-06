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
    bool isUnivalTree(TreeNode* root) {
        set<int> ans;
        solve(root , ans);
        return (ans.size() == 1);
    }

    void solve(TreeNode* node , set<int> &ans){
        if(node == nullptr) return;
        ans.insert(node -> val);
        solve(node -> left ,ans);
        solve(node -> right ,ans);
    }
};