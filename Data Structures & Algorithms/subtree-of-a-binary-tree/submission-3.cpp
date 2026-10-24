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
     bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL){
            return 1;
        }
        if(p!=NULL && q==NULL){
            return 0;
        }
         if(p==NULL && q!=NULL){
            return 0;
        }
        if(p->val!=q->val){
            return 0;
        }
        bool left=isSameTree(p->left,q->left);
        bool right=isSameTree(p->right,q->right);
        return left && right;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL){
            return 1;
        }
        if(root!=NULL && subRoot==NULL){
            return 1;
        }
        if(root==NULL && subRoot!=NULL){
            return 0;
        }
        if(isSameTree(root,subRoot)){
            return 1;
        }
        return isSubtree(root->left,subRoot)||isSubtree(root->right,subRoot);
        
    }
};
