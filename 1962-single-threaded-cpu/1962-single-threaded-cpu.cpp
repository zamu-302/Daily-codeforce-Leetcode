class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
std::priority_queue<
    std::pair<int, int>, 
    std::vector<std::pair<int, int>>, 
    std::greater<>
> pq;
    int n=tasks.size();
    std::vector<std::array<int,3>> nums;
    nums.reserve(n);
    for(int i=0;i<tasks.size();i++){
        nums.push_back({tasks[i][0],tasks[i][1],i});
    }
    sort(nums.begin(),nums.end());
        
    std::vector<int> ans;
    ans.reserve(n);
    int i=0;
    long long time=0;
    while(ans.size()<n){
        if(pq.empty() && time<nums[i][0]){
            time=nums[i][0];
        }
        while( i<n&&nums[i][0]<=time){
            pq.push({nums[i][1],nums[i][2]});
            i++;
        }
        auto[proc,index]=pq.top();
        pq.pop();
        ans.emplace_back(index);
        time+=proc;
    }
        return ans;
    }
};