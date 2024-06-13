#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        int last_ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long ans = 0;
            for (auto i : piles) {
                ans += ceil((i + mid - 1) / mid); // ceil(i / (double) mid)
            }
            if (ans <= h) {
                high = mid - 1;
                last_ans = mid;
            } else {
                low = mid + 1;
            }
        }
        return last_ans;
    }
};
