class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans=0;
        std::unordered_map<int,int> seen;
        int curr=0;
        seen[0]=1;
        for(int i=0;i<nums.size();++i){
            curr+=nums[i];
            if(seen.contains(((curr%k)+k)%k)){
                ans+=seen[((curr%k)+k)%k];
            }
            seen[((curr%k)+k)%k]++;
        }
        return ans;
        
    }
};