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

    bool findTarget(TreeNode* root, int k) {
        vector<int> nodes;
        solve(root , nodes);
        int i = 0 , j = nodes.size() - 1;
        while( i < j){
            if( nodes[i] + nodes[j] == k) return true;
            else if (nodes[i] + nodes[j] > k) j--;
            else i++;
        }
        return false;
    }

    void solve(TreeNode* node , vector<int> &nodes){
        if(node == nullptr) return ;
        solve(node -> left , nodes);
        nodes.push_back(node -> val);
        solve(node ->  right , nodes);
    }
};