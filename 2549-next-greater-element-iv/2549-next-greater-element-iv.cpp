class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        std::vector<int> ans(n,-1);
        std::priority_queue<std::pair<int,int> ,std::vector<std::pair<int,int>>,greater<std::pair<int,int>>>pq;
        std::vector<int> stk;
        for(int i=0;i<n;i++){
            while(!pq.empty()&&nums[i]>pq.top().first){
                ans[pq.top().second]=nums[i];
                pq.pop();
            }
            while(!stk.empty()&& nums[stk.back()]<nums[i]){
                pq.push({nums[stk.back()],stk.back()});
                stk.pop_back();
            }
            
            stk.push_back(i);
        }
        return ans;




    }
};