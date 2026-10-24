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
    bool bst(TreeNode* root,int minv,int maxv){
        if(root==NULL){
            return 1;
        }
        if(root->val<=minv||root->val>=maxv){
            return 0;
        }
        return bst(root->left,minv,root->val) && bst(root->right,root->val,maxv);
    }
public:
    bool isValidBST(TreeNode* root) {
        return bst(root,INT_MIN,INT_MAX);
    }
};
