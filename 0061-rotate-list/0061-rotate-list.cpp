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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        ListNode* temp = head;
        int n = 0;
        while(temp != NULL){
            n++;
            temp = temp->next;
        }
       
        int num = k%n ;
         
        // cout << "num before " << num << endl;
        num = n-num;
        if(num == n){
            return head;
        }
        // cout << "num after " << num << endl;
        temp = head;
        ListNode* newhead;
        for(int i = 0 ; i < num-1; i++){
            temp = temp->next;
        }
        // cout << "temp val " << temp->val << endl;
        newhead = temp->next;
        temp->next = NULL;
        ListNode* newtemp = newhead;
        while(newtemp->next != NULL){
            newtemp = newtemp->next;
        }
        newtemp->next = head;
        
        return newhead;
    }
};