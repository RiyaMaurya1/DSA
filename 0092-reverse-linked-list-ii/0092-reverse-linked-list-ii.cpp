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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* saveleft;
        ListNode* saveright;
        ListNode* newhead;
        ListNode* newlast;
        ListNode* prev;
        ListNode* curr = head;
        ListNode* temp;
        int step = 1;
        while(step != left){
            saveleft = curr;
            curr = curr->next;
            step++;
        }
        int once = 0;
        while(step <= right){
            if(step == right){
                saveright = curr->next;
            }
            if(once != 1){
                newlast = curr;
                once++;
            }
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            if(step != right){
                curr = temp;
            }
            step++;
        }
        if(left != 1){
            saveleft->next = curr;
            newlast ->next = saveright;
            return head;
        }
        else{
            newlast->next = saveright;
            return curr;
        }
        return head;
    }
};