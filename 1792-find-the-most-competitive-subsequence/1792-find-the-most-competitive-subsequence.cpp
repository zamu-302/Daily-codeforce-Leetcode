class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        std::vector<int>stk;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            while(!stk.empty()&&stk.size()-1+n-i>=k && stk.back()>nums[i]){
                stk.pop_back();
            }
            if(stk.size()!=k){
            stk.emplace_back(nums[i]);
            }
        }
        return stk;
    }
};