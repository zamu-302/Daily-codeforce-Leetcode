class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        std::priority_queue<int,std::vector<int>>pq;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int val=matrix[i][j];
                if(pq.size()<k || pq.top()>val){
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