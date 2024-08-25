#include <bits/stdc++.h>

using namespace std;

int faster = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        int ans = -1;
        while (low <= high) {
            int mid = (high + low) / 2;
            int count = 0;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= mid) count++;
            }

            if (count <= mid) {
                low = mid + 1;
            } else if (count > mid) {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};
