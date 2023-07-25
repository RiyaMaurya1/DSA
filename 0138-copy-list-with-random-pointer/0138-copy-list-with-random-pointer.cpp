/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* temp = head;
        Node* prev;
        Node* head2;
        bool once = false;
        unordered_map <Node*, Node*> mp;

        while(temp != NULL){
            int val = temp->val;
            Node* newnode = new Node(val);
            if(once == false){
                head2 = newnode;
                prev = head2;
                once = true;
            }
            else{
                prev->next = newnode;
            }
            mp[temp] = newnode;
            prev = newnode;
            temp = temp->next;

        }

        temp = head;
        while(temp != NULL){
            Node* clonenode = mp[temp];
            Node* randomnode = temp->random;

            Node* clonerandom = mp[randomnode];

            clonenode->random = clonerandom;
            temp = temp->next; 
        }
        return head2;
    }
};