#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int ans = (int) position.size();
        vector<pair<int, float>> all;
        int i, j;
        for (int i = 0; i < position.size(); i++) {
            all.push_back(make_pair(position[i], (target - position[i]) / (float) speed[i]));
        }
        sort(all.begin(), all.end());

        for (i = 0; i < position.size(); i++)  {
            for (j = i + 1; j < position.size(); j++) {
                if (all[i].second <= all[j].second) {
                    ans -= j - i;
                    i = j - 1;
                    break;
                }
            }
        }
        return ans;
    }
};
