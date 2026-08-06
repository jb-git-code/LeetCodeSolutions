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
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> res;
        solve(root , res , path);
        return res;
    }

    void solve(TreeNode* node , vector<string> &res ,string path){
        if(node == NULL) return;
        if(!path.empty()){
            path += "->";
        }
        path += to_string(node -> val);
        if(node -> left == NULL && node -> right == NULL){
            res.push_back(path);
            return;
        }
        solve(node -> left , res ,path );
        solve(node -> right , res , path);
    }
};