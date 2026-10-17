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
    bool inbetween(int a,int c,int b){
        if((a<c&&c>b)||(a>c&&c<b)){
            return true;
        }
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode * temp=head;
        ListNode* prev=head;
        int minindex=std::numeric_limits<int>::max();
        int maxindex=std::numeric_limits<int>::min();
        int mini=std::numeric_limits<int>::max();;
        int maxi=-1;
        temp=temp->next;
        int i=1;
        while(temp->next){
            if(inbetween(prev->val,temp->val,temp->next->val)){
                if(minindex!=std::numeric_limits<int>::max()){
                 mini=std::min(mini,i-maxindex);
                 maxi=std::max(maxi,i-minindex);   
                }
                minindex=std::min(minindex,i);
                maxindex=std::max(maxindex,i);
            }
            i++;
            prev=prev->next;
            temp=temp->next;
        }
        if(mini==std::numeric_limits<int>::max()){return {-1,-1};}
        return {mini,maxi};

    }
};