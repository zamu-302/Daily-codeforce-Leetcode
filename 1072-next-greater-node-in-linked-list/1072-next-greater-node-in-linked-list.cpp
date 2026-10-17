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
    vector<int> nextLargerNodes(ListNode* head) {
        if(head->next==nullptr){
            return {0};
        }
        std::vector<int> arr;
        while(head){
            arr.emplace_back(head->val);
            head=head->next;
        }
        std::vector<int> stk;
        std::vector<int> ans(arr.size(),0);
        stk.emplace_back(0);
        for(int i=1;i<arr.size();i++){
            while(!stk.empty()){
                if(arr[stk.back()]<arr[i]){
                    ans[stk.back()]=arr[i];
                    stk.pop_back();
                }
                else{
                    break;
                }
            }
            stk.emplace_back(i);
        }
       return ans;
    }
};