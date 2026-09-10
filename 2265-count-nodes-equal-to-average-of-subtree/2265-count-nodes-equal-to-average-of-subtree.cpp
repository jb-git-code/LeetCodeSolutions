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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0 ;
        pair<int,int> total = subtreeSum(root , ans);
        return ans;
    }

    pair<int,int> subtreeSum(TreeNode* node , int &ans ){
        if( node == nullptr) return make_pair(0,0);
        if( node -> left == nullptr && node -> right == nullptr) {
            ans += 1;
            return make_pair(node -> val , 1);
        }
        pair<int,int> left = subtreeSum(node -> left , ans );
        pair<int,int> right = subtreeSum(node -> right ,ans );

        int avg = (left.first + right.first + node -> val) / (left.second + right.second + 1);
        if(avg == node -> val) ans++;
        return make_pair(left.first + right.first + node -> val , left.second + right.second + 1);
    }
};