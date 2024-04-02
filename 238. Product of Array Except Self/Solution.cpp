#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<int> mulstarts, mulends(nums.size());
        mulstarts.push_back(1);
        for (int i = 0; i < nums.size(); i++) {
            mulstarts.push_back(mulstarts[i] * nums[i]);
        }
        // for (int x : mulstarts) 
        //     cout << x << " ";
        mulends[nums.size() - 1] = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            mulends[i] = mulends[i+1] * nums[i+1];
        }
        // for (int x : mulends) 
        //     cout << x << " "; 
        for (int i  = 0; i < nums.size(); i++) {
            nums[i] = mulstarts[i] * mulends[i];
        }        
        return nums;
    }
};
