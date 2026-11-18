class Solution {
public:
    std::vector<std::vector<int>>ans{};
    void dfs(vector<int>& nums,vector<int>&pos,int start){
        if(pos.size()>=2){
            ans.push_back(pos);      
        }

        std::unordered_set<int> used;
        
        for(int i=start;i<nums.size();i++){
            if(!pos.empty() && pos.back()>nums[i]){
                continue;
            }
            if(used.contains(nums[i])){
                continue;
            }

            used.insert(nums[i]);
            pos.push_back(nums[i]);
            dfs(nums,pos,i+1);
            pos.pop_back();
        }

    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> pos{};
        dfs(nums,pos,0);
        return ans;
    }
};