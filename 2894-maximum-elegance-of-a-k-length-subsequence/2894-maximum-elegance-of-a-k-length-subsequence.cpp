class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
       std::priority_queue<int,std::vector<int>,greater<int>>pq;
      sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] > b[0];
    });
       std::unordered_map<int,int> types;
       unsigned long long sum=0;
       long long total=0;
       for(int i=0;i<items.size();++i){
        int val=items[i][0];
        int cat=items[i][1];
       if (i < k) {
                total += val;
                if (types.contains(cat)) pq.push(val); 
                else types[cat]++;
            } else {
                if (types.contains(cat) || pq.empty()) continue;
                total += val - pq.top();
                pq.pop();
                types[cat]++;
            }
            sum = max(sum, total + (long long)types.size() * types.size());
       }
       return sum;

    }
};