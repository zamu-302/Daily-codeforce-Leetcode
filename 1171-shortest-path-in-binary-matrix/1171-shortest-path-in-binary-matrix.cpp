class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;
       
       std::vector<std::pair<int,int>> dirs{
         {-1, -1}, {-1, 0},
         {-1, 1},{0, -1}, 
         {0, 1},{1, -1},
         {1, 0},  {1, 1}
       };

       queue<array<int,3>>q;
       vector<vector<bool>> visited(n,vector<bool>(n,false));

       q.push({0,0,1});
       visited[0][0]=true;


       while(!q.empty()){
        auto[r,c,dist]=q.front();
        q.pop();

        if(r==n-1&&c==n-1){
            return dist;
        }
        for(auto [dr,dc]:dirs){
            int nr=r+dr,nc=c+dc;

            if(nc>=0&& nr< n && nr>=0 && nc<n && grid[nr][nc] == 0 && !visited[nr][nc]){
                visited[nr][nc]=true;
                q.push({nr,nc,dist+1});
            }
        }
        
        }
        return -1;
    }
};