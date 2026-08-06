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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,int> parent;
        pair<int,int> dep;
        int depth = 0;
        solve(root , x , y ,parent ,dep,depth);
        return (parent.first != parent.second && dep.first == dep.second);

    }

    void solve(TreeNode* node , int x , int y ,pair<int,int> &parent,pair<int,int> &dep, int depth){
        if(node == NULL) {
            return ;
        }
        if (dep.first != 0 && dep.second != 0) return;
        if(parent.first == 0 || parent.second == 0){
            TreeNode* left = node -> left;
            TreeNode* right = node -> right;
            if(left != NULL && left -> val == x){
                parent.first = node -> val;
            }

            if(left != NULL && left -> val == y){
                parent.second = node -> val;
            }

            if(right != NULL && right -> val == x){
                parent.first = node -> val;
            }

            if(right != NULL && right -> val == y){
                parent.second = node -> val;
            }
        }
        if(node -> val == x){
            dep.first = depth;
        }
        if(node -> val == y){
            dep.second = depth;
        }
        solve(node -> left , x , y,parent,dep,depth + 1);
        solve(node -> right , x ,y,parent,dep,depth + 1);
        
    }


};