class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=wage.size();
        std::vector<std::pair<double,int>> arr;
        for(int i=0;i<n;++i){
            arr.emplace_back(double(wage[i])/quality[i],quality[i]);
            
        }

        std::sort(arr.begin(),arr.end());

        std::priority_queue<int>pq;
        double ans=std::numeric_limits<double>::max();
        double sum=0;
        for(int i=0;i<arr.size();i++){
            if(pq.size()<k || pq.top()>arr[i].second){
                sum+=arr[i].second;
                pq.push(arr[i].second);
                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
            }
            if(pq.size()==k){
                ans=std::min(ans,sum*arr[i].first);
            }
        }
        return ans;
      

    }
};