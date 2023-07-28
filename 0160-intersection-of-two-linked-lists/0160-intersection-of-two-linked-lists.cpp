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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map <ListNode*, int> mp;
        ListNode* temp = headA;
        
        while(temp != NULL){
            mp[temp]++;
            temp = temp->next;
        }
        
        temp = headB;
        while(temp != NULL){
            mp[temp]++;
            temp = temp->next;
        }
        
        for(auto node : mp){
            if(node.second == 2){
                return node.first;
            }
        }
        
        // ListNode* node;
        return NULL;
    }
};