class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int max_height=0;
        while(left<right){
            int curr=((right-left)*std::min(height[left],height[right]));
            if(height[left]<=height[right]){
                left++;
            }
            else{
                right--;
            }
            max_height= max_height>=curr? max_height:curr;
            
        }
        return max_height;
        
    }
};