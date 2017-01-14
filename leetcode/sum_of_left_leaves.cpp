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
    int sumOfLeftLeaves(TreeNode* root) {
      //check if left is a leaf 
      if(!root){
        return 0; 
      }

      int curr = 0; 
      if(root->left){
        if(!root->left->left){
          if(!root->left->right){
            curr += root->left->val; 
          }
        }
      }

      curr += sumOfLeftLeaves(root->left);
      curr += sumOfLeftLeaves(root->right);
      return curr; 
    }
};
