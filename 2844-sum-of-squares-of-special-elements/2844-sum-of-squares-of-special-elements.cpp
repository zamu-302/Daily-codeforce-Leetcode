class Solution {
public:
    constexpr int sumOfSquares(vector<int>& nums)noexcept {
        int n= nums.size();
        int ans=pow(nums[0],2);
        for(int i=2;i<n+1;i++){
            ans+=(n%i==0)? (pow(nums[i-1],2)):0;
        }
        return ans;

        
    }
};