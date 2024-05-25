#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        int i1 = 0, i2  = numbers.size() - 1;

        while (true) {

            int s = numbers[i1] + numbers[i2];
            if (s < target) {
                i1++;
            } else if (s > target) {
                i2--;
            } else {
                break;
            }
        }

        return {i1 + 1, i2 + 1};
    }
};
