class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        std::priority_queue<int,std::vector<int>,greater<int> > seen;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=1;j<n;++j){
                matrix[i][j]^=matrix[i][j-1];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;++j){
                matrix[i][j]^=matrix[i-1][j];
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;j++){
                if(seen.size()<k){
                    seen.push(matrix[i][j]);
                }
                else{
                    if(seen.top()<matrix[i][j]){
                        seen.pop();
                        seen.push(matrix[i][j]);
                    }
                }
            }
        }
        return seen.top();


    }
};