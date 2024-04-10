#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int max = 0, last = 0, cur = 1;
        sort(nums.begin(), nums.end());
        if (nums.size() > 0) {
            last = nums[0];
        } else {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == last + 1) {
                cur += 1;
            } else if (nums[i] != last) {
                if (cur > max) {
                    max = cur;
                }
                cur = 1;
            }
            last = nums[i];
        }
        if (cur > max) {
            max = cur;
        }
        return max;
    }
};
