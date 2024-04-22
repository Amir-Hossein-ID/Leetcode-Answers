#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        unordered_set<string> ans;
        
        if (n==0) {
            return vector<string> {""};
        }
        for (string i : generateParenthesis(n-1)) {
            ans.insert("(" + i + ")");
        }
        for (int i = 1; i < n; i++) {
            vector<string> temp = generateParenthesis(i);
            for (string k : generateParenthesis(i)) {
                for (string j : generateParenthesis(n-i)) {
                    ans.insert(k+j);
                }
            }
        }
        vector<string> a (ans.begin(), ans.end());
        return a;
    }
};
