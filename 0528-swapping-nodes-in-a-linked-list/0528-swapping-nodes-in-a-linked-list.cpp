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
    constexpr ListNode* swapNodes(ListNode* head, int k)noexcept {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* front=head;
        ListNode* prev=head;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        int count=0;
        temp=head;
        int last=n-k+1;
        if(last==k){
            return head;
        }
        while(count!=std::max(last,k)&& temp){
            count++;
            if(count==k){
                front=temp;
            }
            else if(count==last){
                prev=temp;
            }
            temp=temp->next;
        }
        std::swap(front->val,prev->val);
        return head;


                
    }
};