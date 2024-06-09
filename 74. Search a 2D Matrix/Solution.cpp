#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s = matrix[0].size();
        int low = 0;
        int high = matrix.size() * s - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int mx = mid / s;
            int my = mid % s;
            if (matrix[mx][my] == target) {
                return true;
            } else if (matrix[mx][my] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
};
