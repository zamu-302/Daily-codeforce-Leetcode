class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> ans(temperatures.size(),0);
        std::vector<int> stk;
        stk.emplace_back(0);
        for(int i=1;i<temperatures.size();++i){
            while(!stk.empty()&&temperatures[stk.back()]<temperatures[i]){
                ans[stk.back()]=i-stk.back();
                stk.pop_back();
            }
            
            stk.emplace_back(i);            
        }
        return ans;
        
    }
};