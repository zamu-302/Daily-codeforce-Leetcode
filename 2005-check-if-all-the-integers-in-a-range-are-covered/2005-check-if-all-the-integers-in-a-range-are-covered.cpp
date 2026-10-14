class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
         std::vector<int>nums(52,0);
       
        for(const auto& r:ranges){
            int s=r[0];
            int e=r[1];
            nums[s]++;
            nums[e+1]--;
            
        }
       
        for(int i=1;i<52;i++){
            nums[i]+=nums[i-1];
            if(left<=i && i<=right){
                if(nums[i]<=0){
                    std::cout<<nums[i];
                    return false;
                }
            }
        }
        return true;
        
    }
};