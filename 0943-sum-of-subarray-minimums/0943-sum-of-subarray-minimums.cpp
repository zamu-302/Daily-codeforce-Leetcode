class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long MOD=pow(10,9)+7;
        std::vector<int> left(n);
        std::vector<int> right(n);
        std::vector<int>stk;
        std::vector<int>stk2;
        for(int i=0;i<n;i++){
            while(!stk.empty()&& arr[stk.back()]>=arr[i]){
                stk.pop_back();
            }
            
            left[i]=(stk.empty())? -1:stk.back();
            stk.push_back(i);
        }

        for(int i=n-1;i>=0;i--){
            while(!stk2.empty()&&arr[stk2.back()]>arr[i]){
                stk2.pop_back();
            }
            right[i]= (stk2.empty())? n:stk2.back();
            stk2.push_back(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int L=i-left[i];
            int R=right[i]-i;

            long long contribution= (L*R)%MOD;
            long long total=(contribution*arr[i])%MOD;
            ans=(ans+total)%MOD;

        }
        return ans;
        
    }
};