class Solution {
public:
    constexpr vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries)noexcept {
        std::vector<int>ans;
        int q=queries.size();
        int n=nums.size();
        for(int i=0;i<q;i++){
            std::priority_queue<std::pair<std::string,int>,std::vector<std::pair<std::string,int>>,greater<std::pair<std::string,int>>> pq;
            for(int j=0;j<n;j++){
                pq.push({nums[j].substr(nums[j].size()-queries[i][1]),j});
            }
            for(int j=0;j<queries[i][0]-1;j++){
                pq.pop();
            }
            ans.emplace_back(pq.top().second);

        }
        return ans;



    }
};