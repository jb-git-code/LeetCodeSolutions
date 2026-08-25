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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,   0 , n-1);
    }

    TreeNode* solve(vector<int> &arr ,  int low , int high){
        //base condition 
        if(low > high ) return nullptr;

        //build node
        int index = low;
        for(int i = low + 1 ; i <= high ; i++){
            if(arr[i] > arr[index]) index = i;
        }
        TreeNode* temp = new TreeNode(arr[index]);

        temp -> left = solve(arr , low , index - 1 );

        temp -> right = solve(arr ,  index + 1 , high);

        return temp;
    }
};