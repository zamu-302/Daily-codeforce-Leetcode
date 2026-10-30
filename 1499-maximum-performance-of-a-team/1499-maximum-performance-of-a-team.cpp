class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        std::priority_queue<int,std::vector<int>,greater<int>>pq;
        std::vector<std::pair<int,int>> arr;
        for(int i=0;i<n;i++){
            arr.emplace_back(efficiency[i],speed[i]);
        }
        sort(arr.begin(),arr.end(),[](auto a,auto b){return a>b;});
        long long sum=0;
        long long best=std::numeric_limits<int>::min();
        for(int i=0;i<n;i++){
            pq.push(arr[i].second);
            sum+=arr[i].second;
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            best=std::max(sum*arr[i].first,best);
        
        }
        return best%1'000'000'007;
        

        
        
    }
};