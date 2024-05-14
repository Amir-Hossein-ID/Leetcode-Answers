#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int ans = 0;
        vector<pair<int, int>> possible_ans;
        int t, p;
        for (int i = 0; i < heights.size(); i++) {
            bool should_add = true;
            int to_add = 1;
            for (int j = 0; j < possible_ans.size(); j++) {
                t = possible_ans[j].first;
                p = possible_ans[j].second;
                if (heights[i] > t) {
                    possible_ans[j].second += 1;
                } else if (heights[i] == t) {
                    possible_ans[j].second += 1;
                    should_add = false;
                } else {
                    if (ans < t*p) {
                        ans = t*p;
                    }
                    to_add = max(to_add, p + 1);
                    possible_ans.erase(possible_ans.begin()+j);
                    j--;
                }
            }
            if (should_add) {
                possible_ans.push_back(make_pair(heights[i], to_add));
            }
        }
        for (int j = 0; j < possible_ans.size(); j++) {
            t = possible_ans[j].first;
            p = possible_ans[j].second;
            if (ans < t*p) {
                ans = t*p;
            }
        }
        
        return ans;
    }
};
