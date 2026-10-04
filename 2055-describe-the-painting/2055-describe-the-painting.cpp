class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
       std::map<int,long long> seen;
       for(const auto& segment:segments ){
            seen[segment[0]]+=segment[2];
            seen[segment[1]]-=segment[2];
        }
      std::vector<std::vector<long long>> ans;
      long long prev=0, value=0;
      for(const auto& [key,val] :seen){
        if(value!=0){ans.push_back({prev,key,value});}
            prev=key;
            value+=val;
        }
    return ans;

        
    }
};