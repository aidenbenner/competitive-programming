/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 **/
class Solution {
public:


  TreeNode * get_last(TreeNode * root){
    if(root == nullptr){
      return nullptr; 
    }
  
    TreeNode * val = get_last(root); 

    if(val == nullptr){
      return root; 
    }
    return val; 
  }

    TreeNode * flatify(TreeNode* root)
    {
      if(root == nullptr){
        return nullptr; 
      }

      //need to add left node onto end
      TreeNode * left = flatify(root->left); 
        root->left = left; 
      //get last node 

      TreeNode * last = get_last(left); 
      TreeNode * right = flatify(root->right); 
        last->right = right; 

      return root; 
    }

    void flatten(TreeNode* root) {
      flatify(root); 
    }
};
