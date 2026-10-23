class Node{
    public:
    Node(int key,int val): val{val}, key{key}{}
    Node * prev;
    Node* next;
    int freq=1;
    int key;
    int val;
};
class DList{
public:
    Node* head;   
    Node* tail;   

    
    DList(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    void pushFront(Node* node){
        Node* prev=head;
        Node* next=head->next;

        prev->next=node;
        node->prev=prev;
        
        node->next=next;
        next->prev=node;
    }
    void remove(Node* node){
        Node* prev=node->prev;
        Node* next=node->next;

        prev->next=next;
        next->prev=prev;
    }
    bool empty(){
        return head->next==tail;
    }
    Node* back(){
        return tail->prev;
    }
    
};



class LFUCache {
    int capacity;
    int minFreq = 0;
    std::unordered_map<int, Node*> keyToNode;
    std::unordered_map<int, DList> freqToList;
    void touch(Node* node) {
        freqToList[node->freq].remove(node);
        if(freqToList[node->freq].empty()&& node->freq==minFreq){
            minFreq++;
        }
        node->freq++;
        freqToList[node->freq].pushFront(node);
      
    }

public:
    LFUCache(int capacity) : capacity(capacity) {}

    
    int get(int key) {
        if (!keyToNode.count(key)) return -1;
    Node* node = keyToNode[key];
    touch(node);
    return node->val;
        
    }
    
    
    void put(int key, int value) {
         if (capacity == 0) return;

    if (keyToNode.count(key)) {
        Node* node = keyToNode[key];
        node->val = value;
        touch(node);
        return;
    }

    if ((int)keyToNode.size() == capacity) {
        DList& lst = freqToList[minFreq];
        Node* victim = lst.back();
        lst.remove(victim);
        keyToNode.erase(victim->key);
        delete victim;
    }

    Node* node = new Node(key, value);
    keyToNode[key] = node;
    freqToList[1].pushFront(node);
    minFreq = 1;
    }

};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */