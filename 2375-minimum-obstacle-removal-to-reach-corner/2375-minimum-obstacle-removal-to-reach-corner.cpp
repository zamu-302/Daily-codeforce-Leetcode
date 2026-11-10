class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        std::priority_queue<std::pair<int,std::pair<int,int>>,std::vector<std::pair<int,std::pair<int,int>>>,greater<std::pair<int,std::pair<int,int>>>>pq;
        std::vector<std::vector<int>>dist(grid.size(),std::vector<int>(grid[0].size(),INT_MAX));
        int n=grid.size();
        int m=grid[0].size();
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!pq.empty()){
            int d=pq.top().first;
            auto [r,c]=pq.top().second;
            pq.pop();
            if (d > dist[r][c]) continue; 
            if (r == n - 1 && c == m - 1) return d;
            
            for(auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];
                
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int new_dist = d + grid[nr][nc];
                    
                 
                    if(dist[nr][nc] > new_dist) {
                        dist[nr][nc] = new_dist; 
                        pq.push({new_dist, {nr, nc}});
                    }
                }
            }






        }
        return dist[n-1][m-1];
        
    }
};