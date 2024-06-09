#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int pos = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return pos != nums.size() && nums[pos] == target ? pos : -1;
    }
};
