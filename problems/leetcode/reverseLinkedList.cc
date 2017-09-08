/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      if(m - n == 0) return head;
      auto curr = head;
      ListNode* last = NULL; 

      for(int i = 1; i<m; i++){
        last = curr;
        curr = curr->next;
      }

      ListNode* preList = last;  
      ListNode* startRev = curr;  

      for(int i = 1; i<n - m; i++){
        auto tmp = curr->next;
        curr->next = last;
        last = curr;
        curr = tmp;
      }

      startRev->next = curr->next;
      if(m == 1){
        return curr;
      }
      preList->next = last;
      return head;
    }
};
