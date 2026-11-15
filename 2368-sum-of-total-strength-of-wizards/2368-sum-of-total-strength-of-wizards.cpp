class Solution {
public:
    int totalStrength(vector<int>& strength) {
        int n = strength.size();
        long long MOD = 1e9 + 7;
        std::vector<int>left(n,-1);
        std::vector<int>right(n,n);
        std::vector<int> stk;
        for(int i=0;i<n;i++){
            while(!stk.empty()&& strength[stk.back()]>=strength[i]){
                stk.pop_back();
            }
            if(!stk.empty()){
                left[i]=stk.back();
                }
            stk.emplace_back(i);
        }
        stk.clear();
        for(int i=n-1;i>=0;i--){
             while(!stk.empty()&& strength[stk.back()]>strength[i]){
                stk.pop_back();
            }
            if(!stk.empty()){
                right[i]=stk.back();
                }
            stk.emplace_back(i);
        }
        std::vector<long long>prefix(n+1,0);
        std::vector<long long> ss(n+2,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=(prefix[i]+strength[i])% MOD;
        }
        for(int i=0;i<=n;i++){
            ss[i+1]=(ss[i]+prefix[i])%MOD;
        }
        long long total_sum=0;
        for(int i=0;i<n;i++){
        long long L = left[i];
            long long R = right[i];

            long long left_count = i - L;
            long long right_count = R - i;

            long long sum_right = (ss[R + 1] - ss[i + 1] + MOD) % MOD;
            long long sum_left = (ss[i + 1] - ss[L + 1] + MOD) % MOD;

            long long positive_term = (left_count * sum_right) % MOD;
            long long negative_term = (right_count * sum_left) % MOD;

            long long sub_sum = (positive_term - negative_term + MOD) % MOD;
            
           
            long long current_contribution = (strength[i] * sub_sum) % MOD;
            total_sum = (total_sum + current_contribution) % MOD;
        }
        return total_sum;




      
        
    }
};