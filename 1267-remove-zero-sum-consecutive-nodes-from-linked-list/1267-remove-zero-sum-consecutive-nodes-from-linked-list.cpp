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
    constexpr ListNode* removeZeroSumSublists(ListNode* head)noexcept {
        std::unordered_map<int,ListNode*> seen;
        ListNode* front=new ListNode(0,head);
        ListNode *curr=front;
        int prefix=0;
        seen[0]=front;
        while(curr){
            prefix+=curr->val;
            seen[prefix]=curr;
            curr=curr->next;
        }
        prefix=0;
        curr=front;
        while(curr){
            prefix+=curr->val;
            curr->next=seen[prefix]->next;
            curr=curr->next;
        }
        return front->next;
        
    }
};