#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int n = nums.size();
        vector<int> ans(n);
        int cur = 1;
        int i = 0;
        for (i = 0; i < n; i++) {
            ans[i] = cur;
            cur *= nums[i];
        }
        cur = 1;
        for (i = n - 1; i >= 0; i--) {
            ans[i] *= cur;
            cur *= nums[i];
        }
        return ans;
    }
};
