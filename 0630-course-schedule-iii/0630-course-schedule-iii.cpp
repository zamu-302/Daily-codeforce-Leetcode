class Solution {
public:
    constexpr int scheduleCourse(vector<vector<int>>& courses)noexcept {
        std::priority_queue<int>pq;
        sort(courses.begin(),courses.end(),[](const std::vector<int>& a,const std::vector<int>& b){return a[1]<b[1];});
        int total=0;

        for(const auto& c:courses){
            if(c[0]>c[1]){
                continue;
            }
            total+=c[0];
            pq.push(c[0]);
            if(total>c[1]){
                total-=pq.top();
                pq.pop();
            }
        }
        return pq.size();
        
    }
};