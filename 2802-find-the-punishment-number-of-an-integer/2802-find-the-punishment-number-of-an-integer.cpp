class Solution {
public:
   
    bool dfs(int curr,const std::string& num,int start, int target){
        if(curr>target){
            return false;
        }
        if(start==num.length()){
            return curr==target;
        }

        for(int end=start+1;end<=num.length();end++){
            int c=std::stoi(num.substr(start,end-start));
            if(dfs(curr+c,num,end,target)){
                return true;
            }
        }
        return false;       
    }
    int punishmentNumber(int n) {
        int ans=0;
        for(int i=1;i<=n;i++){
            if(dfs(0,std::to_string(i*i),0,i)){
                ans+=(i*i);
            }
        }
        return ans;
        
    }
};