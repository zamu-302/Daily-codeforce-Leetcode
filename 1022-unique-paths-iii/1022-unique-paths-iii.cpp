class Solution {
public:
    int count=0;
    int n;
    int m;
    int targetx;
    int targety;
    int target;
    void dfs(vector<vector<int>>& grid,int i,int j,int c,vector<vector<bool>>& visited){
        if(i<0||j<0||i>=n||j>=m||visited[i][j]|| grid[i][j] == -1){
            return;
        }
        if(i==targetx&&j==targety){
            if(c==target){
                count++;
            }
            return;
        }

        visited[i][j]=true;
        dfs(grid,i+1,j,c+1,visited);
        dfs(grid,i-1,j,c+1,visited);
        dfs(grid,i,j+1,c+1,visited);
        dfs(grid,i,j-1,c+1,visited);
        visited[i][j]=false;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int startx;
        int starty;
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    targetx=i;
                    targety=j;
                }
                else if(grid[i][j]==1){
                    startx=i;
                    starty=j;
                }
                else if(grid[i][j]==-1){
                    k++;
                }
            }
        }
        target=n*m-1-k;
        dfs(grid,startx,starty,0,visited);
        return count;

    }
};