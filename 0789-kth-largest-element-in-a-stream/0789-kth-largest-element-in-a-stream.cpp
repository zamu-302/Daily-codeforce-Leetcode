class KthLargest {
public:
    KthLargest(int k, vector<int>& nums): k{k} {
        for(const auto& num:nums){
            add(num);
            }
     }
    
    int add(int val) {
        if(pq.size()<k || pq.top()<val){
            pq.push(val);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
    private:
    int k;
    std::priority_queue<int,std::vector<int>,greater<int>> pq;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */