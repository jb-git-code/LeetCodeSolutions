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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        bool flag = false;
        solve(root , ans ,flag, val);
        return ans;
    }

    void solve(TreeNode *node , TreeNode* &ans ,bool &flag , int x){
        if(node == nullptr || ans) return ;

        if(node -> val == x){
            ans = node;
            flag = true;
            return;
        }

        if(x < node -> val) solve(node -> left , ans ,flag , x);
        else solve(node -> right , ans ,flag , x);
    }
};