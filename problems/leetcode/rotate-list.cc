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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0) return head;
        if(head == nullptr) return nullptr;
        ListNode* curr = head;
        ListNode* last = curr;
        int size = 0; 
        while(curr != NULL){
          size++; 
          last = curr;
          curr = curr->next;
        }
        k = k % size;

        last->next = head;

        curr = head;
        int makeNull = size - k; 
        for(int i = 1; i<makeNull; i++){
          curr = curr->next;
        }
        ListNode* ret = curr->next;
        curr->next = NULL;

        return ret;
    }
};

