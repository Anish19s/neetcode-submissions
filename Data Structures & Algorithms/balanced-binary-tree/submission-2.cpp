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
    int maxDepth(TreeNode* root) {
         if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL){
            return 1;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        return max(left,right)+1;  
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return 1;
        }
        int left=maxDepth(root->left);
        int right=maxDepth(root->right);
        if((right-left)>1||(left-right)>1){
            return 0;
        }
        return isBalanced(root->left)&& isBalanced(root->right);
    }
};
