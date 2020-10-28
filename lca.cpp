/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p or root == q)
            return root;
        TreeNode *rht = lowestCommonAncestor(root->right,p,q);
        TreeNode *lft = lowestCommonAncestor(root->left,p,q);
        
        if(rht and lft){
            return root;
        }
        if(!rht and !lft){
            return NULL;
        }
        return rht == NULL ? (lft == NULL ? NULL: lft) : rht; 
    }
};