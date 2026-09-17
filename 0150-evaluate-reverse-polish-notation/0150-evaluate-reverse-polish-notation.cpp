class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> stk;

        
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="*"||tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="/"){
            int val1 = stk.back(); stk.pop_back();
            int val2 = stk.back(); stk.pop_back();
            if(tokens[i]=="*"){
                stk.emplace_back(val1*val2);
            }
            else if(tokens[i]=="/"){
                stk.emplace_back(val2/val1);
            }
            else if(tokens[i]=="-"){
                stk.emplace_back(val2-val1);
            }
            else{
            stk.emplace_back(val1+val2);
            }
            
            }
            else{
          
            stk.emplace_back(std::stoi(tokens[i]));
            }

        }
        return stk[0];
        
    }
};