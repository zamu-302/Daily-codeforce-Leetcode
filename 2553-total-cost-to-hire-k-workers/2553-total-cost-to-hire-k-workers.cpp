class Solution {
public:
    constexpr long long totalCost(vector<int>& costs, int k, int c)noexcept {
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,greater<>> left;
        std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,greater<>> right;

        long long sum=0;
        int n=costs.size();
        int i=0;
        int j=n-1;

        if(2*c>=n){
            for(int m=0;m<n;m++){
            left.push({costs[m],m});}
            for(int z=0;z<k;z++){
                sum+=left.top().first;
                left.pop();
            }
            return sum;
        }
        else{
        while(i<c||n-c-1<j){
            if(i<c){
            left.push({costs[i],i});
            i++;
            }
            if(n-c-1<j){
                right.push({costs[j],j});
                j--;
            }
        }
        for(int a=0;a<k;a++){
            bool takeLeft;
            if(right.empty()) takeLeft=true;
            else if(left.empty()) takeLeft=false;
            else takeLeft = left.top().first<=right.top().first;
            if(takeLeft){
                sum+=left.top().first;
                left.pop();
                 if(i<=j){
                left.push({costs[i],i});
                i++;
            }
            }
            else{
                sum+=right.top().first;
                right.pop();
                if(i<=j){
                right.push({costs[j],j});
                j--;
                }
            }
        }
        return sum;
        }

    }
};