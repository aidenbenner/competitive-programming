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
    int rob_no(TreeNode* root)
    {
      if(root == nullptr){
        return 0; 
      }
      int out = rob(root->left) + rob(root->right);
      return out; 
    }

    int rob(TreeNode* root) {
      if(root == nullptr){
        return 0; 
      }
      int out = rob_no(root->left) + root->val + rob_no(root->right);
      out = max(out, rob(root->left) + rob(root->right));
      return out;
    }
};
