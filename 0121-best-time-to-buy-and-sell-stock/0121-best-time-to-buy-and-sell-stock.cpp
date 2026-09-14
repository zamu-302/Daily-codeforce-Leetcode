class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left=0;
        int profit=0;
        for(int right=0;right<prices.size();right++){
            if(prices[right]>prices[left]){
                profit=std::max(profit,prices[right]-prices[left]);
            }
            else{
                left=right;
            }

        }
        return profit;
    }
};