class Solution {
public:
    constexpr long long maxScore(vector<int>& nums1, vector<int>& nums2, int k)noexcept  {
        std::vector<std::array<int,3>> nums;
        
        std::priority_queue<int,std::vector<int>,greater<int>>pq;
        int n=nums1.size();
        nums.reserve(n);
        for(int i=0;i<n;i++){
            nums.emplace_back(std::array<int, 3>{nums2[i],nums1[i],i});
        }
        long long ans=std::numeric_limits<long long>::min();
        long long sum=0;
        sort(nums.begin(),nums.end(), std::greater<std::array<int,3>>());
        for(int i=0;i<n;i++){
            if(k-1>=i){
                pq.push(nums[i][1]);
                sum+=nums[i][1];
                if(k-1==i){
                    std::cout<<sum;
                    ans=std::max(ans,nums[i][0]*sum);
                }
            }
            else{
                sum-=pq.top();
                pq.pop();
                pq.push(nums[i][1]);
                sum+=nums[i][1];
                ans=std::max(ans,nums[i][0]*sum);
            }
            
        }
        return ans;

        
    }
};