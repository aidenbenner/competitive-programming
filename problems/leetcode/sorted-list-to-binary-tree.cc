/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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

  TreeNode *sortedToBST(ListNode *left, int n){
    if(n <= 1){
      return 

    }
      curr = left;
      for(int i = 0; i<n/2 + 1; i++){
        curr = curr->next;
      }

      TreeNode * head = new TreeNode; 

      head->left = sortedToBST(head, size/2 - 1);
      head->right = sortedToBST(curr, size - size/2 - 1);

      return head;


  }


    TreeNode* sortedListToBST(ListNode* head) {
      ListNode * curr = head;
      int size = 0; 
      while(curr->next != NULL){
        size++; 
        curr = curr->next;
      }

      curr = head;
      for(int i = 0; i<size/2 + 1; i++){
        curr = curr->next;
      }

      TreeNode * head = new TreeNode; 

      head->left = sortedToBST(head, size/2 - 1);
      head->right = sortedToBST(curr, size - size/2 - 1);

      return head;
    }
};
