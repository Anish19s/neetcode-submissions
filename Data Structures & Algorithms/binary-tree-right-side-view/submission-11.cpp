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
    vector<int> rightSideView(TreeNode* root) {
       queue<TreeNode*>q;
       q.push(root);
        vector<int>v;
        if(root==NULL){
            return v;
        }
        while(!q.empty()){
            int level=q.size();
            for(int i=0;i<level;i++){
                 TreeNode* top=q.front();
                q.pop();
                if(i==level-1){
                    v.push_back(top->val);
                }

                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
        return v;
    }
};
