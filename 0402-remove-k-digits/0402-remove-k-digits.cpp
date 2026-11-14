class Solution {
public:
    string removeKdigits(string num, int k) {
        std::string stk;
        int n=num.length();
        for(int i=0;i<n;i++){
            while(!stk.empty()&&k>0&&(stk.back()>num[i])){
                stk.pop_back();
                k--;
            }
            if (!stk.empty() || num[i] != '0') {
            stk.push_back(num[i]);
            }
        }
        while(!stk.empty()&&k>0){
            stk.pop_back();
            k--;
        }

    return stk.empty()? "0":stk;
        
    }
        
    
};