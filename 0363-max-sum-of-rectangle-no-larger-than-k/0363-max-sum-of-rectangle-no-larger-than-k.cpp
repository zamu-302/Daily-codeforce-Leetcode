class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        int col= matrix[0].size();
        int ans=std::numeric_limits<int>::min();
        for(int i=0;i<row;i++){
            std::vector<int> cols(col);
            for(int j=i;j<row;j++){
                for (int c = 0; c < col; c++) {
                    cols[c] += matrix[j][c];
                }
                int p=0;std::set<int> seen{0};
                for(int c=0;c<col;c++){
                    p+=cols[c];
                    auto it=seen.lower_bound(p-k);
                    if(it!=seen.end()){
                        ans=std::max(ans,p-*it);
                    }
                    seen.insert(p);
                }
            }
        }
        return ans;

        
    }
};