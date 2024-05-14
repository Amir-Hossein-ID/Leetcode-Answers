#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int ans = 0;
        int temp, cur, si;
        vector<int> lefts;
        vector<int> rights;
        si = heights.size();
        for (int i = 0; i < si; i++) {
            lefts.push_back(0);
            rights.push_back(si - 1);
        }
        for (int i = 1; i < si; i++) {
            temp = i;
            cur = heights[i];
            while (temp > 0 && heights[temp - 1] >= cur) {
                temp = lefts[temp - 1];
            }
            lefts[i] = temp;
            temp = si - i - 1;
            cur = heights[temp];
            while (temp < si - 1 && heights[temp + 1] >= cur) {
                temp = rights[temp + 1];
            }
            rights[si - i - 1] = temp;
        }
        for (int i = 0; i < si; i++) {
            temp = (rights[i] - lefts[i] + 1) * heights[i];
            if (temp > ans) {
                ans = temp;
            }
        }
        return ans;
    }
};
