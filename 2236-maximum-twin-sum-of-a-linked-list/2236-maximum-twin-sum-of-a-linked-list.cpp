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
    int pairSum(ListNode* head) {
        std::vector<int> arr;
        while (head){
            arr.emplace_back(head->val);
            head=head->next;
        }
        int left=0;
        int right=arr.size()-1;
        int maxi=0;
        while(left<right){
            maxi=std::max(maxi,arr[left]+arr[right]);
            right--;
            left++;
        }
        return maxi;
        
    }
};