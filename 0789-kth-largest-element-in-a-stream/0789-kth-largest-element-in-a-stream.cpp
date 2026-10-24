class KthLargest {
public:
    int k;
    std::priority_queue<int,std::vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums): k{k} {
        for(const auto& num:nums){
            add(num);
            }
     }
    
    constexpr int add(int val) noexcept{
        if (pq.size()<k || pq.top()<val){
            pq.emplace(val);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */