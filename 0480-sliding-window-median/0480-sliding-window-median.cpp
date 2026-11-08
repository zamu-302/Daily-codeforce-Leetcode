class Solution {
public:
    bool is_even=false;
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    std::multiset<int>seen(nums.begin(),nums.begin()+k);
    int n=nums.size();
    auto mid=next(seen.begin(),(k-1)/2);
    std::vector<double> ans;
    ans.reserve(n-k+1);
    is_even=(k%2==0);
    for(int i=k;;++i){
        if(is_even){
        ans.push_back(((double)*mid+*next(mid))/2);
        }
        else{
        ans.push_back((double)*mid);
        }
        if(i==n){break;}

        //  add the new value;
        seen.insert(nums[i]);
        if(nums[i]<*mid){--mid;}


        //remove the old value;
        if(nums[i-k]<=*mid)++mid;
        seen.erase(seen.lower_bound(nums[i-k]));
    }
    return ans;


    }
};