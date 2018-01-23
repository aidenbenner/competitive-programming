/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cmath>

using namespace std;


// 3/5 => 1 1 1 0 0 

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size = 0; 
        auto curr = root;
        while(curr != nullptr){
            size++; 
            curr = curr->next;
        }

        int higher = size % k;
        int x = size / k;

        vector<ListNode*> out; 

        ListNode* lastCurr = nullptr;
        curr = root;
        for(int i = 0; i<k; i++){
            out.push_back(curr); 
            int s = 0; 
            if(curr == nullptr) continue;
            for(int i = 0; i<x; i++){
                lastCurr = curr;
                curr = curr->next;
            }
            if(higher){
                lastCurr = curr;
                curr = curr->next;
                higher--; 
            }
            if(lastCurr){
                lastCurr->next = nullptr;
            }
        }
        return out;
    }
};
