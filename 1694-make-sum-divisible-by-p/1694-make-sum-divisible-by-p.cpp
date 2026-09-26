class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        //idea is we add the total sum like all the arr then we make a prefix sum checking if it reaches the reminder if so we talk the length of the smallest??

        long long total_sum = std::accumulate(nums.begin(), nums.end(), 0LL);
        int reminder=total_sum%p;
        if(reminder==0){
            return 0;
        }
        std::unordered_map<int,int> seen;
        seen[0]=-1;
        long long curr=0;
        int ans=nums.size();
        for(int i=0;i<nums.size();i++){
            curr=(curr+nums[i])%p;
            if(seen.count((curr-reminder+p)%p)){
                ans=std::min(ans,i-seen[(curr-reminder+p)%p]);
            }
            seen[curr]=i;
        }
        return ans==nums.size()? -1: ans;
    }
};