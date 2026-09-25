class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        std::unordered_map<int,int> seen;
        seen[0]=-1;
        int ans=0;
        int curr=0;
        for(int right=0;right<nums.size();right++){
            curr+=(nums[right]==1)? 1:-1;
            if(seen.count(curr)){
                ans=std::max(ans,right-seen[curr]);
            }
            else{
                seen[curr]=right;
            }
        }
        return ans;

    }
};