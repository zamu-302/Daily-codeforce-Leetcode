class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<int,std::vector<int>>pq;
        pq.push(matrix[0][0]);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i==0&& j==0){continue;}
                int val=matrix[i][j];
                if(pq.top()>val||pq.size()<k){
                    pq.push(val);
                    if(pq.size()>k){
                        pq.pop();
                    }
                }
            }
        }
        return pq.top();
    }
};