class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
    return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
});
        int ans=1;
        int i=1;
        while(i<intervals.size()){
            int start=intervals[i-1][0];
            int end=intervals[i-1][1];
            while(start<=intervals[i][0] && end>=intervals[i][1]){
                i++;
                if(i>=intervals.size()){
                    return ans;
                }
            }
            i++;
            ans++;
        }
        return ans;
    }
};