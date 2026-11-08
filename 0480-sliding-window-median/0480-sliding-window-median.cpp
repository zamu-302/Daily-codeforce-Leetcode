class Solution {
public:
    bool iseven = false;

    // mid points at the (lower) middle element of the sorted window
    double find_mid(multiset<int>::iterator mid) {
        if (iseven) {
            auto nxt = next(mid);                 // the upper middle
            return ((double)*mid + *nxt) / 2;     // cast first: avoids int overflow
        }
        return *mid;
    }

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), (k - 1) / 2);
        iseven = (k % 2 == 0);

        vector<double> ans;
        for (int i = k; ; i++) {
            ans.push_back(find_mid(mid));         // answer for the current window
            if (i == (int)nums.size()) break;     // that was the last window

            // add the new element
            window.insert(nums[i]);
            if (nums[i] < *mid) --mid;

            // remove the element leaving the window
            if (nums[i - k] <= *mid) ++mid;
            window.erase(window.lower_bound(nums[i - k]));
        }
        return ans;
    }
};