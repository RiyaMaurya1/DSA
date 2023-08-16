/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // timecomplexity = O(n);
    // Space complexity = O(1);
    
    ListNode* partition(ListNode* head, int x) {

        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* left = new ListNode(0);
        ListNode* right = new ListNode(0);
        
        ListNode* l = left;
        ListNode* r = right;
        
        while(temp != NULL){
             ListNode* newnode = new ListNode(temp->val);
            if(temp->val < x){
                l->next = newnode;
                l = newnode;
                temp = temp->next;
            }
            else{
                r->next = newnode;
                r = newnode;
                temp = temp->next;
            }
            
        }
        r->next = NULL;
        l->next = right->next;
        
        
        return left->next;
    }
};