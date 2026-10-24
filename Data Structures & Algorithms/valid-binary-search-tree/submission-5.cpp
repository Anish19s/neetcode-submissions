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
    bool bst(TreeNode* root,int mini,int maxi){
        if(!root){
            return 1;
        }
        if(root->val<=mini||root->val>=maxi){
            return 0;
        }
        return bst(root->left,mini,root->val) && bst(root->right,root->val,maxi);
    }
public:
    bool isValidBST(TreeNode* root) {
        return bst(root,INT_MIN,INT_MAX);
    }
};
