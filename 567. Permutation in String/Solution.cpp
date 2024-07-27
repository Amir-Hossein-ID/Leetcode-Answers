#include <bits/stdc++.h>

using namespace std;

int faster = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> counts(26);
        for (char c: s1) {
            counts[c - 'a']++;
        }
        int len = s1.size();
        int curLen = 0;
        vector<int> ccopy (counts);
        for (int i = 0; i < s2.size(); i++) {
            if (ccopy[s2[i] - 'a'] > 0) {
                curLen++;
                ccopy[s2[i] - 'a']--;
                if (curLen == len) return true;
            } else if (counts[s2[i] - 'a'] > 0) {
                while (s2[i - curLen] != s2[i]) {
                    ccopy[s2[i - curLen] - 'a']++;
                    curLen--;
                }
            } else {
                ccopy = counts;
                curLen = 0;
            }
        }

        return false;
    }
};
