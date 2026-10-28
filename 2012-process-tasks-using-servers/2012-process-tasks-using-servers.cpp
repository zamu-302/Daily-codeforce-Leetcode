class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    using ll=long long;
     std::priority_queue<std::array<ll,2>,std::vector<std::array<ll,2>>,greater<std::array<ll,2>>>pq;
     std::priority_queue<std::array<ll,3>,std::vector<std::array<ll,3>>,greater<std::array<ll,3>>>busy;
     int n=servers.size();
     for(int i=0;i<n;i++){
        pq.push({servers[i],i});
     } 
     int m=tasks.size();
     std::vector<int> ans;
     ans.reserve(m);
     ll time=0;
     
    for(int i=0;i<m;i++){
        time=std::max(time, (ll)i);
        if(pq.empty()){time=busy.top()[0];}

        while(!busy.empty() && busy.top()[0]<=time){
            pq.push({busy.top()[1],busy.top()[2]});
            busy.pop();
        }

        auto val=pq.top();
        pq.pop();
        ans.push_back(val[1]);
        busy.push({time+tasks[i],val[0],val[1]});
        }
    return ans;
        }
    
     

};