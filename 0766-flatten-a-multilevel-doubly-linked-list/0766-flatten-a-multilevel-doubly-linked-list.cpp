/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *head2=new Node();
    Node* tail=head2;
    void dfs(Node* node){
        if(!node){
            return;
        }
        Node* newNode = new Node(node->val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        dfs(node->child);
        dfs(node->next);
        

    }
    Node* flatten(Node* head) {
        if(!head){
            return head;
        }
        dfs(head);
        Node *res=head2->next;
        res->prev=nullptr;
        return res;
    }
};