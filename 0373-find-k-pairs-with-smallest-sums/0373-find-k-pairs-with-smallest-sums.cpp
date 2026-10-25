class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        std::vector<std::vector<int>> ans(k);

        std::priority_queue<std::vector<int>>pq;
        for(int i=0;i<nums1.size();i++){
            
            if(pq.size()==k && nums1[i]+nums2[0]>=pq.top()[0]){
                break;
            }

            for(int j=0;j<nums2.size();j++){
                if(pq.size()<k||nums1[i]+nums2[j]<pq.top()[0]){
                    pq.push({nums1[i]+nums2[j],i,j});
                    if(pq.size()>k){
                        pq.pop();
                    }
                }
                else if(pq.size()==k && nums1[i]+nums2[j]>pq.top()[0]){
                    break;
                }
            }
        }
        for(int i=0;i<k;i++){
            auto val=pq.top();
            pq.pop();
            ans[k-i-1]={nums1[val[1]],nums2[val[2]]};
        }
        return ans;
    
    
    
    }
};