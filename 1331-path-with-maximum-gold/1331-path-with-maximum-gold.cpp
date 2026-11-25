class Solution {
public:
    int n;
    int m;
    int score=0;
    void dfs(vector<vector<int>>& grid,int i,int j,int curr,vector<vector<bool>>& visited){
        if (i<0||j<0||i>=n||j>=m){
            return;
        }
        if(grid[i][j]==0||visited[i][j]){
            return;
        }
        visited[i][j]=true;
        dfs(grid,i+1,j,curr+grid[i][j],visited);
        dfs(grid,i-1,j,curr+grid[i][j],visited);
        dfs(grid,i,j+1,curr+grid[i][j],visited);
        dfs(grid,i,j-1,curr+grid[i][j],visited);
        visited[i][j]=false;
        score=std::max(score,curr+grid[i][j]);


    }
    int getMaximumGold(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        std::vector<std::vector<bool>>visited(n,std::vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    continue;
                }
              
                dfs(grid,i,j,0,visited);
            }
        }
        return score;        
    }
};