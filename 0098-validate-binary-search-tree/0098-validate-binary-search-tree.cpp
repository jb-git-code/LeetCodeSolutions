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
    bool isValidBST(TreeNode* root) {
        vector<int> path;
        inOrder(root ,path);

        for(int i = 1 ; i < path.size() ; i++){
            if(path[i] <= path[i-1]) return false;
        }

        return true;
    }

    void inOrder(TreeNode* node , vector<int> &path){
        if(node == nullptr) return;
        inOrder(node -> left , path);
        path.push_back(node -> val);
        inOrder(node -> right , path);
    }
};