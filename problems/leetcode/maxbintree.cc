/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define INF 1e8
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        int m = nums[0];
        int ind = 0; 
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > m) {
                ind = i; 
                m = nums[i]; 
            }
        }
        TreeNode* root = new TreeNode(m); 
        vector<int> left; 
        vector<int> right; 
        for(int i = 0; i<ind; i++){
            left.push_back(nums[i]); 
        }
        for(int i = ind + 1; i<nums.size(); i++){
            right.push_back(nums[i]); 
        }
        root->left = constructMaximumBinaryTree(left); 
        root->right= constructMaximumBinaryTree(right); 
        return root;
    }


    TreeNode* fast(vector<int>&a){
        if(a.size() == 0) return nullptr;
        vector<int> tmp;
        int ind = 0; 
        int last = a[0] - 1; 
        int curr = a[0];
        while(ind != a.size()){
            last = curr;
            curr = tmp[ind];
            tmp.push_back(curr);

        }
    }
};



