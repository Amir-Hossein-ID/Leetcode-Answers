#include <bits/stdc++.h>

using namespace std;

int faster = []() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int beg = 0, end = 0;
        int ans = 0;
        set<char> in_group;
        while (end < s.size()) {
            while (in_group.find(s[end]) != in_group.end()) {
                in_group.erase(s[beg]);
                beg++;
            }
            in_group.insert(s[end]);
            ans = max(ans, end - beg + 1);
            end++;
        }
        return ans;
    }
};
