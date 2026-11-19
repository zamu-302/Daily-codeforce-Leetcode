class Solution {
public:
    int count=0;
    unordered_set<string>seen;
    void dfs(const string& s,int c,int start){
        if(c+s.length()-start<=count){
            return;
        }
        if(start==s.length()){
            count=std::max(c,count);
            return;
        }
        for(int end=start+1;end<=s.length();end++){
            string piece=s.substr(start,end-start);
            if(seen.contains(piece)){
                continue;
            }
            seen.insert(piece);
            dfs(s,c+1,end);
            seen.erase(piece);
        }
    }
    int maxUniqueSplit(string s) {
        dfs(s,0,0);
        return count;
        
            }
};