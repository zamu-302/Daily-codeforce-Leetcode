class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
       std::unordered_map<int,std::vector<long long>>seen;
       std::vector<long long> ans(nums.size(),0LL);
       for(int i=0;i<nums.size();i++){
        seen[nums[i]].push_back(i);
       } 
       for(const auto& p:seen){
        const auto& group=p.second;
        long long total=std::accumulate(group.begin(),group.end(),0LL);
        long long prefixTotal=0;
        for(int i=0;i<group.size();i++){
            ans[group[i]]= total-prefixTotal*2+ group[i]*(2*i-group.size());
            prefixTotal+=group[i];
        }
       }
       return ans;
    }
};