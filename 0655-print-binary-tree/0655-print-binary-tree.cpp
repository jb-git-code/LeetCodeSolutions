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
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root) - 1;
        int r = h + 1;
        int c = pow(2.0 , h+1) - 1 ;
        vector<vector<string>> matrix (r , vector<string> (c ,""));
        solve(root , 0 , (c - 1) / 2 , matrix , h);
        return matrix;
    }

    int height(TreeNode* node){
        if(node == nullptr) return 0;
        return 1 + max(height(node -> left) , height(node -> right));
    }

    void solve(TreeNode* node , int r , int c , vector<vector<string>> &matrix , int h){
        if(node == NULL) return;
        matrix[r][c] = to_string(node->val);

        if(node -> left){
            solve(node -> left , r+1, c - (1 << (h - r - 1)), matrix , h);
        }

        if(node -> right){
            solve(node -> right , r+1, c + (1 << (h - r - 1)) , matrix , h);
        }
    }
};