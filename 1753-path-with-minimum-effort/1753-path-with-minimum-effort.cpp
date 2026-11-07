class Solution {
public:
    int min_score=std::numeric_limits<int>::max();
    int n;
    int m;
    vector<vector<bool>> visited;  
    bool dfs(vector<vector<int>>& heights,int i,int j,int prev,int k){
        if(i<0||i>=n||j<0||j>=m){
            return false;
        }
        if(visited[i][j]){return false;}
        if(std::abs(heights[i][j]-prev)>k){
            return false;
        }
        if(i==n-1&&j==m-1){
            return true;
        }
        


        
        prev=heights[i][j];
        visited[i][j]=true;
        return dfs(heights,i+1,j,prev,k)||dfs(heights,i,j-1,prev,k)||dfs(heights,i-1,j,prev,k)||dfs(heights,i,j+1,prev,k);
       

    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n=heights.size();
        m=heights[0].size();
        int l=0;
        int r=1000000;
        while(l<r){
            int mid=l+(r-l)/2;
            visited.assign(n, vector<bool>(m, false));
            if(dfs(heights,0,0,heights[0][0],mid)){r=mid;}
            else{ l=mid+1;}

        }
        return l;
        
        dfs(heights,0,0,0,heights[0][0]);
        
        return min_score;
    }
};