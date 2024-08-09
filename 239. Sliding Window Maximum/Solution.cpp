#include <bits/stdc++.h>

using namespace std;

int faster = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxes(nums.size() - k + 1);
        deque<int> replaces;
        for (int i = 0; i < k; i++) {
            while (replaces.size() > 0 && nums[i] > replaces.back()) {
                replaces.pop_back();
            }
            replaces.push_back(nums[i]);
        }
        int ans = 0;
        maxes[ans] = replaces.front();
        ans++;
        for (int i = k; i < nums.size(); i++) {
            if (replaces.front() == nums[i - k]) {
                replaces.pop_front();
            }
            while (replaces.size() > 0 && nums[i] > replaces.back()) {
                replaces.pop_back();
            }
            replaces.push_back(nums[i]);
            maxes[ans] = replaces.front();
            ans++;
        }
        return maxes;
    }
};
