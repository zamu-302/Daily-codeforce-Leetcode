class StockSpanner {
public:
    StockSpanner() {
    
    }
    
    constexpr int next(int price)noexcept {
        int i=1;
        while(!stk.empty()&&stk.back().first<=price){
            i+=stk.back().second;
            stk.pop_back();
        }
        stk.push_back({price,i});
        return i;
    }
 private:
 std::vector<std::pair<int,int>> stk;
 


};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */