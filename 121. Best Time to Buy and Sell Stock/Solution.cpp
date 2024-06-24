#include <bits/stdc++.h>

using namespace std;

int faster = []() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int min = prices[0];
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                ans = max(ans, prices[i] - min);
            }
        }
        return ans;
    }
};
