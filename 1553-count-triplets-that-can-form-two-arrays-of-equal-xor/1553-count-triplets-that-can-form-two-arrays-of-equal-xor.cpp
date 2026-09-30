class Solution {
public:
    int countTriplets(vector<int>& arr) {   
        int ans=0;
        uint64_t mask=0;
        for(int i=0;i<arr.size();++i){
            mask^=arr[i];
            uint64_t mask2=arr[i];
            for(int j=i+1;j<arr.size();++j){
                mask2^=arr[j];
                if(!mask2){
                    ans+=j-i;
                }
            }
           
        }
        return ans;
    }
};