class Solution {
public:
    int count=0;
    unordered_set<string> seen;
    void dfs(const string& tile,const std::string& curr,std::vector<bool>&used){
        for(int i=0;i<tile.length();i++){
            if(used[i]){
                continue;
            }
            if(seen.contains(curr+tile[i])){
                continue;
            }
            used[i]=true;
            seen.insert(curr+tile[i]);
            count++;
            dfs(tile,curr+tile[i],used);
            used[i]=false;
        }

    }
    int numTilePossibilities(string tiles) {
        std::string forward="";
        std::vector<bool>used(tiles.length(),false);
        dfs(tiles,forward,used);
        
        
        
       
        return count;
    }

};