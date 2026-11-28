class Solution {
public:
    int n;
    int best;
    vector<int> loads;

    void dfs(vector<int>& jobs, int i, int curr_max) {
        if (i == n) {
            best = curr_max;
            return;
        }
        for (int w = 0; w < loads.size(); w++) {
            if (loads[w] + jobs[i] >= best) {
                continue;
            }

            loads[w] += jobs[i];
            dfs(jobs, i + 1, max(curr_max, loads[w]));
            loads[w] -= jobs[i];
            if (loads[w] == 0) {
                break;
            }
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        n = jobs.size();
        if (k == n) {
            return std::ranges::max(jobs);
        }
        std::ranges::sort(jobs, std::greater());
        best = std::ranges::fold_left(jobs, 0, std::plus());
        loads.assign(k, 0);

        dfs(jobs, 0, 0);
        return best;
    }
};