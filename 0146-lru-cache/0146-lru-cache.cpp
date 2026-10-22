class Node{
public:
Node * next=nullptr;
Node * prev=nullptr;
int key;
int val;
Node(int key,int val): key{key}, val{val}{}
};


class LRUCache {
public:
    Node *oldest=new Node(0,0);
    Node * latest= new Node(0,0);

    LRUCache(int capacity):capacity{capacity} {
    oldest->next=latest;
    latest->prev=oldest;    
    }
    
    int get(int key) {
        // check if it's in the map if it's is in we remove it and insert it to the latest. and return it.
        if(hash.contains(key)){
            remove(hash[key]);
            insert(hash[key]);
            return hash[key]->val;
        }
        return -1;
    }
    void remove(Node* node){
        Node* prev=node->prev;
        Node* next=node->next;
        prev->next=next;
        next->prev=prev;
    }
    void insert(Node* node){
        Node* prev=latest->prev;
        Node* next=latest;
        prev->next=node;
        next->prev=node;
        node->next=next;
        node->prev=prev;
    }
    void put(int key, int value) {
        if(hash.contains(key)){
            remove(hash[key]);
        }
        hash[key]= new Node(key,value);
        insert(hash[key]);
        if(hash.size()>capacity){
            auto lru=oldest->next;
            remove(lru);
            hash.erase(lru->key);
        }
    }
private:
int capacity;
std::unordered_map<int,Node*> hash;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */