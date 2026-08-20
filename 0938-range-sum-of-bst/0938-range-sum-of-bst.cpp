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
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> nodes;
        solve(root,nodes);
        int sum = 0;
        for(auto i : nodes){
            if(i >= low && i <= high) sum += i;
        }
        return sum;
    }

    void solve(TreeNode* node , vector<int> &nodes){
        if(node == nullptr) return ;
        solve(node -> left , nodes);
        nodes.push_back(node -> val);
        solve(node -> right , nodes);
    }
};