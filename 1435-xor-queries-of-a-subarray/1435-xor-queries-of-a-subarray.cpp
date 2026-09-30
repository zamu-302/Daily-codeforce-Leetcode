class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        //easiest solution is to do brute for and loop over the queries and go thorought the arr based on that.
        std::unordered_map<int,int> hash;
        hash[-1]=0;
        int mask=0;
        for(int i=0;i<arr.size();++i){
            mask^=arr[i];
            std::cout<<mask<<std::endl;
            hash[i]=mask;
        }
        std::vector<int> ans;
        for(int i=0;i<queries.size();i++){
            ans.emplace_back(hash[queries[i][1]]^hash[queries[i][0]-1]);
        }
        return ans;
    }

};