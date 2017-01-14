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
    bool isSameTree(TreeNode* p, TreeNode* q) {
      //base case left and right nodes are null 

      if(!p){
        if(q){
          return false; 
        }
        return true; 
      }
      else if(!q){
        if(p){
          return false;
        }
        return true;
      }
      
      bool same_val = p->val == q->val; 
      bool left = isSameTree(p->left, q->left);   
      bool right= isSameTree(p->right, q->right);   


      return left && right && same_val; 
    }
};
