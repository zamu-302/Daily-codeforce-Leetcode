class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        //idea count then intersecting the intervals then return that
        std::map<int,int> seen;
        int ans=0;
        for(const auto& s:intervals){
            seen[s[0]]++;
            seen[s[1]+1]--;
        }
        int val=0;
        for(const auto&[key,value]:seen){
            val+=value;
            ans=std::max(ans,val);
        }
        return ans;
    }
};