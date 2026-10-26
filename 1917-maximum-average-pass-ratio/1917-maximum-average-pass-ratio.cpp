class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        std::priority_queue<std::tuple<double,int,int>>pq;
        auto val = [](double p, double t) {
            return (p + 1) / (t + 1) - p / t;
        };
        double avg=0;
        for(const auto& c:classes){
            pq.push({val(c[0],c[1]),c[0],c[1]});
            avg+=double(c[0])/c[1];
        }
        std::cout<<avg<<std::endl;
        while(extraStudents--){
            auto [g,p,t]=pq.top();
            pq.pop();
            avg+=g;
            auto gain=val(double(p+1),double(t+1));
            pq.push({gain,p+1,t+1});
        }
        std::cout<<avg;
        return avg/classes.size();
        
        
    }
};