#include <bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<int> st;
    stack<int> min_st;
    MinStack() {
        ios::sync_with_stdio(0);
        cin.tie(0);
    }
    
    void push(int val) {
        st.push(val);
        if (min_st.empty() || val <= min_st.top()) {
            min_st.push(val);
        }
    }
    
    void pop() {
        if (min_st.top() == st.top()) {
            min_st.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min_st.top();
    }
};
