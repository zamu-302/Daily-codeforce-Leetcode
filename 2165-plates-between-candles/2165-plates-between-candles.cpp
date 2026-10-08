class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        //here is the idea i will have an map where i will store only the prefix sum of the candles and the distance from the previous candle and when we go over the the queries we will use upper bound and lower bound to get the anwer and the in between ?? 

        std::map<int,int> seen;
        int left=-1;
        for(int i=0;i<s.length();++i){
            if(s[i]=='|'){
                seen[i]=(left==-1)? 0:seen[left]+(i-left-1);
                left=i;
            } 
        }
        std::vector<int> ans;
        ans.reserve(queries.size());
        for(auto query:queries){

            auto r=seen.upper_bound(query[1]);
            auto l=seen.lower_bound(query[0]);
            if (l == seen.end() || r == seen.begin()) { ans.push_back(0); continue; }
            --r;
            if(l->first>=r->first){
                ans.push_back(0);
            }
            else{
                ans.push_back(r->second-l->second);
            }                              
            
        }
        return ans;
    }
};