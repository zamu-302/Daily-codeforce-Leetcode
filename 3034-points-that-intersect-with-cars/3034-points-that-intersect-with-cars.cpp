class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        std::vector<int>pos(101,0);
     for(const auto& num:nums){
      pos[num[0]-1]++;
      pos[num[1]]--;
    }
    int ans=(pos[0]>0)?1 :0;
    for(int i=1;i<101;i++){
      pos[i]+=pos[i-1];
      if(pos[i]>0)
      ans++;
    }
    return ans;
        

    }
};