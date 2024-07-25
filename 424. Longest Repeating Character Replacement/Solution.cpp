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
        int total = s.size();
        int ans = 0;
        int left = 0, right = 0;
        int maxelement = 0;
        vector<int> counts(26);
        while (right < total) {
            // the value of maxelement can be incorrect for some windows, but we cannot achieve a better answer with lower maxelement
            // so it doesn't make wrong answers
            maxelement = max(maxelement, ++counts[s[right] - 'A']);
            int replace_size = right - left + 1 - maxelement;
            if (replace_size > k) {
                counts[s[left] - 'A']--;
                left++;
            }
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;
    }
};
