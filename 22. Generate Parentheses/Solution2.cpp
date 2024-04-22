#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        vector<string> ans;
        func(&ans, "", 0, 0, n);
        return ans;
    }

    void func(vector<string> *v, string cur, int lefts, int rights, int n) {
        if (cur.size() == n*2 && lefts == rights) {
            v->push_back(cur);
        }
        if (lefts < n) {
            func(v, cur + "(", lefts + 1, rights, n);
        }
        if (rights < lefts) {
            func(v, cur + ")", lefts, rights + 1, n);
        }
    }
};
