#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int s = nums.size();
        int low = 0, high = s - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                if (target < nums[0] != nums[mid] >= nums[0]) { //XOR
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else { // > target
                if (target < nums[0] != nums[mid] < nums[0]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};
