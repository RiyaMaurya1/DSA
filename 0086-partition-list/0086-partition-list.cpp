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
    ListNode* partition(ListNode* head, int x) {

        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* temp = head;
        ListNode* head2 = new ListNode();
        ListNode* temp2;
        bool flag = false;
        
        while(temp != NULL){
            
            if(temp->val < x){
                if(flag == false){
                    head2->val = temp->val;
                    head2->next = NULL;
                    temp2 = head2;
                    flag = true;
                    temp = temp->next;
                    continue;
                }
                
                ListNode* newnode = new ListNode(temp->val);
                temp2->next = newnode;
                temp2 = newnode;
                temp = temp->next;
            }
            else{
                temp = temp->next;
            }
            
        }
        
        temp = head;
        while(temp != NULL){
            
            if(temp->val >= x){
                if(head->val >= x && flag == false){
                    head2->val = temp->val;
                    head2->next = NULL;
                    temp2 = head2;
                    flag = true;
                    temp = temp->next;
                    continue;
                }
                
                ListNode* newnode = new ListNode(temp->val);
                temp2->next = newnode;
                temp2 = newnode;
                temp = temp->next;
            }
            else{
                temp = temp->next;
            }
            
        }
        return head2;
    }
};