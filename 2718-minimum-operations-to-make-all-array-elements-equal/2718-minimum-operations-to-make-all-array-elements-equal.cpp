class Solution {
public:
    constexpr int findIndex(int num,std::vector<int>& nums)noexcept{
        int left=0;
        int right=nums.size();
        
        while(left<right){
            int mid=left+(right-left)/2;
            
            if(nums[mid]>num){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
    constexpr vector<long long> minOperations(vector<int>& nums, vector<int>& queries)noexcept {
        sort(nums.begin(),nums.end());
        std::vector<long long> prefix(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            prefix[i+1]+=(nums[i]+prefix[i]);
        }
        std::vector<long long> ans(queries.size(),0);
        for(int i=0;i<queries.size();i++){
            long long q=queries[i];
            long long index=findIndex(q,nums);
            long long left=(index*q)-prefix[index];
            long long right=((prefix[nums.size()]-prefix[index])-((nums.size()-index)*q));
            ans[i]+=(left+right);
        }
        return ans;

        
    }
};