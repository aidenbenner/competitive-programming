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
    void f(TreeNode* root){
        if(root == nullptr) return;
        TreeNode* tmp = root->right;
        TreeNode* curr = root->left;
        flatten(root->left); 
        flatten(root->right); 
        if(root->left == nullptr) return;

        while(curr->right != NULL){
            curr = curr->right;
        }
        curr->right = tmp;
        root->right = root->left;
        root->left = nullptr;
    }


    void flatten(TreeNode* root) {
        f(root); 
    }
};
