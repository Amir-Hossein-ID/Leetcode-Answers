#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& heights) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int size = heights.size();
        int ans = 0;
        int wherel = 0, wherer = size - 1;
        int rightMax = heights[wherer], leftMax = heights[wherel];

        while (wherel < wherer) {
            if (leftMax <= rightMax) {
                wherel += 1;
                ans += max(leftMax - heights[wherel], 0);
                leftMax = max(heights[wherel], leftMax);
            } else {
                wherer -= 1;
                ans += max(rightMax - heights[wherer], 0);
                rightMax = max(heights[wherer], rightMax);
            }
        }

        return ans;
    }
};
