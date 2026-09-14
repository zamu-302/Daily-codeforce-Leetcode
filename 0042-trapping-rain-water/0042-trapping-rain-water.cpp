class Solution {
public:
    int trap(vector<int>& height) {
        std::vector<int> leftMax;
        std::vector<int> rightMax(height.size());
        int curr=0;
        for(int i=0;i<height.size();i++){
            curr=std::max(curr,height[i]);
            leftMax.emplace_back(curr);
        }
        curr=0;
        for(int i=height.size()-1;i>-1;i--){
            curr=std::max(curr,height[i]);
            rightMax[i]=curr;
        }
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=std::min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
        
    }
};