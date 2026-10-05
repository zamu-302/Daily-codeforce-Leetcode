class Solution {
public:
    constexpr int intersectionSizeTwo(vector<vector<int>>& intervals)noexcept {
     sort(intervals.begin(),intervals.end(),[](auto a,auto b){return(a[1]!=b[1])? a[1]<b[1]:a[0]>b[0];});
     int a=-1,b=-1,ans=0;
     for(const auto& interval:intervals){
        int s=interval[0];
        int e=interval[1];
        if(a>=s){
            continue;
        }
        if(b>=s){
            ans+=1;
            a=b;
            b=e;
            continue;
        }
            ans+=2;
            a=e-1;
            b=e;
        
     }
     return ans;
    }
};