class Solution {
public:
    constexpr vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries)noexcept {
        std::vector<int>ans;
        int q=queries.size();
        int n=nums.size();
        for(int i=0;i<q;i++){
            std::vector<std::pair<std::string,int>> pq;
            pq.reserve(n);
            for(int j=0;j<n;j++){
                pq.push_back({nums[j].substr(nums[j].size()-queries[i][1]),j});
            }
            std::stable_sort(pq.begin(), pq.end(), [](const auto& a, const auto& a_pair) {
                return a.first < a_pair.first;
            });
            ans.emplace_back(pq[queries[i][0]-1].second);

        }
        return ans;



    }
};