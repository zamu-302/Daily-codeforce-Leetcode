class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        std::vector<int> pos(101, 0);
    for (auto l : logs) {
      pos[l[0] - 1950]++;
      pos[l[1] - 1950]--;
    }
    int ans = 1950;
    int count = pos[0];
    for (int i = 1; i < 101; i++) {
      pos[i] += pos[i - 1];
      if (pos[i] > count) {
        ans = i + 1950;
        count = pos[i];
      }
    }
    return ans;

    }
};