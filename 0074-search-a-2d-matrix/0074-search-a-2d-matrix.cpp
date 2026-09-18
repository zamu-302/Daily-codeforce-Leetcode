class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left=0;
        int right=matrix.size()-1;
        int n=matrix[0].size();
        while(left<=right){
            int mid=(left+right)/2;
            if(matrix[mid][0] <= target && target <= matrix[mid][n - 1]){
                int left1=0;
                int right1=matrix[0].size()-1;
                while(left1<=right1){
                    int mid1=(left1+right1)/2;
                    if(matrix[mid][mid1]==target){
                        return true;
                    }
                    else if(matrix[mid][mid1]>target){
                        right1=mid1-1;
                    }
                    else{
                        left1=mid1+1;
                    }
                }
                return false;

            }
            else if(matrix[mid][0]>target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return false;
    }
};