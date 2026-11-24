class Solution {
public:
   
    int n;
    int m;
    std::vector<std::vector<int>> ans;
    constexpr bool inbound(int i,int j){
        return i>=0&&i<n&&j>=0&&j<m;
    }
    void dfs(std::vector<std::vector<int>>&grid,int i,int j,std::vector<std::vector<bool>>& visited){
        visited[i][j]=true;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};


        for(int k=0;k<4;k++){
        if(!inbound(i+dx[k],j+dy[k])||grid[i+dx[k]][j+dy[k]]<grid[i][j]||visited[i+dx[k]][j+dy[k]]){
            continue;
        }
            dfs(grid,i+dx[k],j+dy[k],visited);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        std::vector<std::vector<bool>> pacificVisited(n,std::vector<bool>(m,false));
        std::vector<std::vector<bool>> atlanticVisited(n,std::vector<bool>(m,false));
        
    for (int j = 0; j < m; j++)
        dfs(heights, 0, j, pacificVisited);

    for (int i = 0; i < n; i++)
        dfs(heights, i, 0, pacificVisited);

    for (int j = 0; j < m; j++)
        dfs(heights, n-1, j, atlanticVisited);

    for (int i = 0; i < n; i++)
        dfs(heights, i, m-1, atlanticVisited);



    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pacificVisited[i][j]&&atlanticVisited[i][j]){
                ans.push_back({i,j});
            }
        }
    }
    return ans;
        
    }
};