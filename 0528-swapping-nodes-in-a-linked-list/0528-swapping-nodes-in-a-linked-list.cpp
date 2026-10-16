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
    ListNode* swapNodes(ListNode* head, int k) {
        std::vector<int> arr;
        while(head){
            arr.emplace_back(head->val);
            head=head->next;
        }
        int temp=arr[k-1];
        arr[k-1]=arr[arr.size()-k];
        arr[arr.size()-k]=temp;
        ListNode *head2=new ListNode();
        ListNode *dummy=head2;
        for(int i=0;i<arr.size();i++){
            dummy->val=arr[i];
            if(i!=arr.size()-1){
                dummy->next=new ListNode();
                dummy=dummy->next;
            }
        }
        return head2;
        
    }
};