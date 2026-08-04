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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res ;
        solve(root , res );
        return res;
    }

    void solve(TreeNode* node , vector<vector<int>> &res){
        if (node == nullptr) return;
        queue<TreeNode*> temp;
        vector<int> arr;
        temp.push(node);
        temp.push(NULL);
        while(!temp.empty()){
            if(temp.front() == NULL){
                res.push_back(arr);
                arr.clear();
                temp.pop();
                if(!temp.empty()){
                    temp.push(NULL);
                }
            }
            else{
                TreeNode* root = temp.front();
                arr.push_back(root->val);
                if(root->left)
                    temp.push(root->left);
                if(root->right)
                    temp.push(root->right);
                temp.pop();
            }
        }
    }
};