#include <bits/stdc++.h>

using namespace std;

int faster = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int characterReplacement(string s, int k) {
        // slow n^2 answer
        int total = s.size();
        int ans = 0;
        for (int i = 0; i < total; i++) {
            char to = s[i];
            int curk = k;
            int j = i + 1;
            while (j < total) {
                if (s[j] != to) curk--;
                if (curk < 0) break;
                j++;
            }
            curk = max(curk, 0);
            ans = max(ans, min(total, j - i + curk));
        }
        return ans;
    }
};
