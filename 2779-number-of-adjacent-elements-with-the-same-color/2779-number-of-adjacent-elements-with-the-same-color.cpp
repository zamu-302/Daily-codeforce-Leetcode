class Solution {
public:
    constexpr vector<int> colorTheArray(int n, vector<vector<int>>& queries)noexcept {
        std::vector<int> nums(n,0);
        std::vector<int> ans(queries.size(),0);
        int c=0;
        int i=0;
        for(const auto& q:queries){
            int index=q[0];
            int color=q[1];
            int pre=(index>0)? nums[index-1]:0;
            int next=(index<n-1)? nums[index+1]:0;
            if(nums[index]){
                c-=(nums[index]==pre)+(nums[index]==next);
            }
            nums[index]=color;
            c+=(nums[index]==pre)+(nums[index]==next);
            ans[i]+=c;
            
            i++;
        }
        return ans;
      
    }
};