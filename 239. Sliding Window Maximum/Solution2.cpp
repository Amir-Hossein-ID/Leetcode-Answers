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
        int ma = nums[0];
        int maind = 0;
        for (int i = 1; i < k; i++) {
            if (nums[i] >= ma) {
                ma = nums[i];
                maind = i;
            }
        }
        int ans = 0;
        maxes[ans] = ma;
        ans++;
        int i = k;
        while (i < nums.size()) {
            if (nums[i] >= ma) {
                ma = nums[i];
                maind = i;
            } else if (i - k == maind) {
                maind = i - k + 1;
                ma = nums[maind];
                for (int j = maind; j <= i; j++) {
                    if (nums[j] >= ma) {
                        ma = nums[j];
                        maind = j;
                    }
                }
            }
            maxes[ans] = ma;
            ans++;
            i++;
        }
        return maxes;
    }
};
