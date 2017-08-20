/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <set>
#include <map>
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      // dfs to find paths to both nodes. 
      // find the first recurring node in each path
      vector<TreeNode*> ptha = DFS(root, p);
      vector<TreeNode*> pthb = DFS(root, q);

      set<TreeNode*> visa;
      for(int i = 0; i<ptha.size(); i++){
        visa.insert(ptha[i]);
      }

      for(int i = 0; i<pthb.size(); i++){
        if(visa.find(pthb[i]) != visa.end()){
          return pthb[i];
        }
      }
      return NULL;
    }


    vector<TreeNode*> DFS(TreeNode* root, TreeNode* search){

      vector<TreeNode*> frontier;
      frontier.push_back(root); 

      map<TreeNode*, TreeNode*> parent;
      while(frontier.size() > 0){
        vector<TreeNode*> next;
        for(int i = 0; i<frontier.size(); i++){
          if(frontier[i] == NULL) continue;
          if(frontier[i] == search){
            // return path
            vector<TreeNode*> out;
            TreeNode* current = search;
            while(parent.find(current) != parent.end()){
              out.push_back(current); 
              current = parent[current]; 
            }
            out.push_back(current);

            return out;
          }
          auto left = frontier[i]->left; 
          if(left != NULL){
            parent[left] = frontier[i];
            next.push_back(frontier[i]->left); 
          }
          auto right = frontier[i]->right;
          if(right != NULL){
            parent[right] = frontier[i];
            next.push_back(frontier[i]->right); 
          }
        }
        frontier = next;
      }
      vector<TreeNode*> out;
      return out;
    }

};
