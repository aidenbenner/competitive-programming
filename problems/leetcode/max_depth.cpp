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
    int maxDepth(TreeNode* root) {
      if(root == NULL){
        return 0;
      }

      int left = 1 + maxDepth(root->left);
      int right = 1 + maxDepth(root->right);

      return std::max(left,right); 
    }
};


