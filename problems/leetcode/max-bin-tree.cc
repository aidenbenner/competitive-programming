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

    TreeNode* build(vector<int>& nums, int n, int start) {
      if(n == 0) return nullptr;
      if(n == 1) return new TreeNode(nums[start]);

      int curr = nums[0]; 
      int ind = start; 
      for(int i = start + 1; i<n; i++){
        if(nums[i] > curr){
          ind = i; 
          curr = nums[i];
        }
      }

      vector<int> left; 
      vector<int> right; 

      for(int i = start; i<n; i++){
        if(i < ind){
          left.push_back(nums[i]);
        }
        else if(i > ind){
          right.push_back(nums[i]);
        }
      }

      auto root = new TreeNode(curr);
      root->left = constructMaximumBinaryTree(left);
      root->right = constructMaximumBinaryTree(right);
        
      return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return build(nums, nums.size(), 0);
    }
};
