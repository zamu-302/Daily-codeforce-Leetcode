class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int currprod=1;
        int no_zero=0;
        int zero_index;
        int n=nums.size();
        std::vector <int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero_index=i;
                no_zero++;
                continue;
            }
            currprod*=nums[i];
        }
        if(no_zero<=1){
            if(no_zero==1){
                ans[zero_index]=currprod;
            }
            else{
                for(int i=0;i<n;i++){
                    ans[i]=currprod/nums[i];
                }
            }
        }
        return ans;
        

    }
};