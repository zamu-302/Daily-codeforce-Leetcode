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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode before{};
        ListNode after{};

        ListNode *be= &before;
        ListNode *af= &after;
        int i=0;
        while(list1){
            if(i<a){
                be->next=list1;
                be=be->next;
            }
            else  if(i>b){
                af->next=list1;
                af=af->next;
            }
            i++;
            list1=list1->next;
        }
        af->next=nullptr;
        ListNode* tail=list2;
        while(tail->next){
            tail=tail->next;
        }
        tail->next=after.next;
        
        be->next=list2;
        return before.next;

        
    }
};