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
    std::vector<int> ans;
    void dfs(Node* node){
        if(!node){
            return;
        }
        ans.emplace_back(node->val);
        dfs(node->child);
        dfs(node->next);
        

    }
    Node* flatten(Node* head) {
        if(!head){
            return head;
        }
        dfs(head);
        Node* head2=new Node(ans[0]);
        Node *tail=head2;
        for (int i = 1; i < ans.size(); ++i) {
        Node* newNode = new Node(ans[i]);
        
      
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        
    }
    return head2;
    }
};