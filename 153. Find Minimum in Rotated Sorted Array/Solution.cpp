#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int si = nums.size();
        int low = 0, high = si - 1;
        int mid = 0;
        while (low < high) {
            mid = (low + high) / 2;
            if (nums[mid] > nums[si - 1]) {
                mid++;
                low = mid;
            } else if ((nums[mid] < nums[0]) || (mid < si - 1 && nums[mid] < nums[mid + 1])) {
                high = mid;
            } else {
                high = low - 1;
                low = 0;
            }
        }
        return nums[mid];
    }
};
