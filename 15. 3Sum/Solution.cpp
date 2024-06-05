#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int temp, t2, j, k, last, last2;
        last = 1e5 + 1;
        for (int i = 0; i < nums.size(); i++) {
            temp = -nums[i];
            if (temp == last) {
                continue;
            }
            last = temp;
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {
                t2 = nums[j] + nums[k];
                if (t2 == temp) {
                    ans.push_back({-temp, nums[j], nums[k]});
                    last2 = nums[j];
                    while (j < k && nums[++j] == last2);
                    last2 = nums[k];
                    while (j < k && nums[--k] == last2);
                    k = min(k + 1, (int) nums.size() - 1);
                } else if (t2 < temp) {
                    j += 1;
                } else {
                    k -= 1;
                }
            }
        }
        return ans;
    }
};
