class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        std::unordered_map<int,int> seen;
        int ans=0;
        int curr=0;
        for(const auto& n:nums){
            curr+=n;
            if(curr==goal){
                ans++;
            }
            if(seen.find(curr-goal)!=seen.end()){
                ans+=seen[curr-goal];
            }
            seen[curr]++;
        }
        return ans;
    }
};