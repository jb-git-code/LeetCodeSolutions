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
    int findTilt(TreeNode* root) {
        int sum = 0;
        int res = solve(root , sum);
        return sum;
    }

    int solve(TreeNode* node , int &sum){
        if(node == nullptr) return 0;
        if(node -> left == nullptr && node -> right == nullptr) return node -> val;
        int leftSum = solve(node -> left , sum);
        int rightSum = solve(node -> right , sum);
        sum += (abs(leftSum - rightSum));
        return leftSum + rightSum + node -> val;
    }
};