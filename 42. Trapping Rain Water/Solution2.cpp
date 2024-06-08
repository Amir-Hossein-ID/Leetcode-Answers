#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& heights) {
        // every height can have "min(rightMax, leftMax) - height" amount of water on top of it
        ios::sync_with_stdio(0);
        cin.tie(0);
        int temp, size = heights.size();
        int ans = 0;
        vector<int> lefts(size, -1);
        vector<int> rights(size, -1);

        for (int i = 0; i < size; i++) {
            lefts[i] = heights[i];
            if (i > 0) {
                lefts[i] = max(lefts[i], lefts[i-1]);
            }

            int newi = size - i - 1;
            rights[newi] = heights[newi];
            if (newi < size - 1) {
                rights[newi] = max(rights[newi], rights[newi+1]);
            }
        }

        for (int i = 0; i < size; i++) {
            ans += max(min(lefts[i], rights[i]) - heights[i], 0);
            cout << lefts[i] << " " << rights[i] << '\n';
        }

        return ans;
    }
};
