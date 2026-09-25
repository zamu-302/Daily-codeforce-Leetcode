class Solution {
public:
    constexpr int summ(std::vector<int>& nums,int goal) noexcept{
        int left=0;
        int right=0;
        int target=0;
        int curr=0;
        while(right<nums.size()){
            curr+=nums[right];
            while(goal<curr && left<=right){
                curr-=nums[left];
                left++;
            }
            if(curr<=goal){
             target+=(right-left+1);
            }
            right++;
        
        }
        return target;
    }

    constexpr int numSubarraysWithSum(vector<int>& nums, int goal) noexcept {
       return summ(nums,goal)-summ(nums,goal-1);
       
    }
};