class Solution {
public:
    
    int ans=std::numeric_limits<int>::max();
    bool dfs(vector<vector<int>>& grid,int i, int j,int mid,std::vector<std::vector<bool>>&visited){
        if(i<0||j<0||j>=grid.size()||i>=grid.size()){
            return false;
        }
        if(visited[i][j]||grid[i][j]>mid){
            return false;
        }
    
    
        if(i==grid.size()-1&&j==grid.size()-1){
         return true;
        }
        visited[i][j]=true;
        
        return dfs(grid,i+1,j,mid,visited)||
        dfs(grid,i-1,j,mid,visited)||
        dfs(grid,i,j+1,mid,visited)||
        dfs(grid,i,j-1,mid,visited);
    


    }
    int swimInWater(vector<vector<int>>& grid) {
       int n = grid.size();
        int lo = grid[0][0], hi = n * n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            if (dfs(grid, 0, 0, mid, visited)) hi = mid; 
            else lo = mid + 1;                          
        }
        return lo;
        
        
    }
};