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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()||inorder.empty()){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[0]);
        int c1=0;
        for(int i=0;i<inorder.size();i++){
            if(inorder[i]==preorder[0]){
                c1=i;
                break;
            }
        }
        vector<int>leftPre(preorder.begin()+1,preorder.begin()+c1+1);
        vector<int>leftin(inorder.begin(),inorder.begin()+c1);
        vector<int>rightPre(preorder.begin()+1+c1,preorder.end());
        vector<int>rightin(inorder.begin()+c1+1,inorder.end());
        root->left=buildTree(leftPre,leftin);
        root->right=buildTree(rightPre,rightin);
        return root;
    }
};
