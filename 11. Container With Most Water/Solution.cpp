#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int left = 0;
        int right = height.size() - 1;
        int cur_height = min(height[right], height[left]);
        int ans = cur_height * (right - left);

        while (left < right) {
            cur_height++;
            while (left < right and height[left] < cur_height) left++;
            while (left < right and height[right] < cur_height) right--;

            cur_height = min(height[right], height[left]);
            ans = max(ans, cur_height * (right - left));
        }

        return ans;
    }
};