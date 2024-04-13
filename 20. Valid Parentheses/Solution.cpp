#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        stack<char> st;
        char temp;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            temp = st.top();
            cout << s[i];
            if (s[i] == ']' && temp == '[') {
                st.pop();
            } else if (s[i] == ')' && temp == '(') {
                cout << "hello";
                st.pop();
            } else if (s[i] == '}' && temp == '{') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};
