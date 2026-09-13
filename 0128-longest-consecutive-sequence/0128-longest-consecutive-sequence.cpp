class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        sort(nums.begin(),nums.end());
        
        int curr=1;
        int maxlen=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if((nums[i]==nums[i-1]+1)){
                curr++;
                continue;
            }
            maxlen=std::max(curr,maxlen);
            curr=1;
        }
        maxlen=std::max(curr,maxlen);
        return maxlen;
    }
};