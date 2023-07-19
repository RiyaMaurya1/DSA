struct Node{
    int key;
    int value;
    Node *prev;
    Node *next;
    
    // Node(int k , int v){
    //     key = k;
    //     value = v;
    // }
    
    Node(int k , int v) : key(k), value(v), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    
    unordered_map<int, Node*> mp;
    int cap;
    
    Node* head  =  new Node (-1, -1);
    Node* tail  =  new Node (-1, -1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    void addnode(Node* newnode){
        Node * temp = head -> next;
        newnode -> next = head -> next;
        head -> next = newnode;
        newnode -> prev = head;
        temp -> prev = newnode;
    }
    
    void deletenode(Node* delnode){
        Node* delprev = delnode -> prev;
        Node* delnext = delnode -> next;
        
        delprev -> next = delnext;
        delnext -> prev = delprev;
        
    }
    
    int get(int key_) {
        if(mp.find(key_) != mp.end()){
            Node* resnode = mp[key_];
            int val = resnode -> value; 
            mp.erase(key_);
            deletenode (resnode);
            addnode(resnode);
            mp[key_] = head-> next;
            return val;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key_, int value_) {
        Node* newnode = new Node(key_, value_);
        // cout << "map size " << mp.size() << endl;
        
        if(mp.find(key_) != mp.end()){
            Node* delnode = mp[key_];
            deletenode(delnode);
            mp.erase(key_);
        }
       
        if(mp.size() >= cap){
            Node* delnode = tail -> prev;
            int delnodekey = delnode -> key;
            deletenode(delnode);
            mp.erase(delnodekey);
       }
        addnode(newnode);
        mp[key_] = head->next;
    }
    
    
};

// ["LRUCache","put","put","get","put","get","put","get","get","get"]
// [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */