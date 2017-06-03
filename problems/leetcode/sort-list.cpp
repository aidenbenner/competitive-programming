#include <cstdio>
#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode * merge(ListNode *a, int an, ListNode* b,int bn){
      ListNode *left= a; 
      ListNode *right= b; 
      int i = 0;
      int j = 0; 


      ListNode * curr;

      if(left->val < right->val){
        curr = left; 
        left = left->next;
        i++; 
      }
      else{
        curr = right;
        right = right->next;
        j++;
      }

      ListNode *start = curr;

      while(i < an && j < bn){
        if(left->val < right->val){
          curr->next = left; 
          curr = left;
          left = left->next;
          i++; 
        }
        else{
          curr->next= right;
          curr = right;
          right = right->next;
          j++;
        }
      }
      while(i < an){
        curr->next = left; 
        curr = left;
        left = left->next;
        i++;
      }
      while(j < bn){
        curr->next= right;
        curr = right;
        right = right->next;
        j++;
      }

      return start;
    }


    ListNode* sort(ListNode* a, int n){
      if(n <= 1){
        return a; 
      }

      ListNode *curr = a;
      for(int i = 0; i<n/2; i++){
        curr = curr->next;
      }

      ListNode *left = sort(a, n/2);
      ListNode *right = sort(curr, n - n/2); 

      ListNode* out = merge(left, n/2, right, n - n/2);  
      return out;
    }

    ListNode* sortList(ListNode* head) {
      int n = 0; 

      ListNode* curr = head; 
      while(curr != NULL){
        n++;
        curr = curr->next;
      }

      head = sort(head,n); 
      return head;
    }
};

ListNode *push(ListNode *last, int a){
  ListNode* next = new ListNode(a); 
  last->next = next;
  return last->next;
}

int main()
{
  ListNode *a = new ListNode(0); 
  a = push(a,5); 
  a = push(a,1); 
  a = push(a,9); 
  a = push(a,8); 
  Solution s; 
  a = s.sortList(a);

  cout << a->val << endl;
}

