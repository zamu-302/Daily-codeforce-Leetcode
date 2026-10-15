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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        std::vector<int> ans;
        while(head){
            ans.emplace_back(head->val);
            head=head->next;
        }
        left--;
        right--;
        while(left<right){
            int temp=ans[left];
            ans[left]=ans[right];
            ans[right]=temp;
            left++;
            right--;
        }
        ListNode *head2=new ListNode(ans[0]);
        ListNode* dummy=head2;
        for(int i=1;i<ans.size();i++){
            dummy->next=new ListNode(ans[i]);
            if(i!=ans.size()-1){
                dummy=dummy->next;
            }
        }
        return head2;
    }
};