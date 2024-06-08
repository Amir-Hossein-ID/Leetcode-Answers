#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int trap(vector<int>& heights) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int temp, size = heights.size();
        int ans = 0;

        int i = 0;
        while (i < size) {
            int j = i + 1;
            // exclude is the amount that should be removed from answer because it was already filled with heights and no water could get trapped
            int exclude = 0;
            // finding next height more than or equal to current height (meaning water can be trapped inside these two)
            while (j < size && heights[j] < heights[i]) {
                exclude += heights[j];
                j++;
            }
            if (j == size) {
                // there was no height more than current one, but there may be some holes in the remaining heights
                // so basically doing the same process but in reverse because we know there is a maximum height (current "i")
                j--;
                while (j > i) {
                    int k = j - 1;
                    exclude = 0;
                    while (k > i && heights[k] < heights[j]) {
                        exclude += heights[k];
                        k--;
                    }
                    if (k == i) {
                        ans += min(heights[i], heights[j]) * max(j - i - 1, 0) - exclude;
                        break;
                    }
                    ans += min(heights[j], heights[k]) * max(j - k - 1, 0) - exclude;
                    j = k;
                }
                break;
            }
            ans += min(heights[i], heights[j]) * max(j - i - 1, 0) - exclude;
            i = j;
        }
        return ans;
    }
};
