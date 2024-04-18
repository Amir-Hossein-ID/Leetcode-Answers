#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        stack<int> oper;
        int temp;
        for (auto i : tokens) {
            if (i == "*") {
                temp = oper.top();
                oper.pop();
                temp *= oper.top();
                oper.pop();
                oper.push(temp);
            } else if (i == "/") {
                temp = oper.top();
                oper.pop();
                temp = oper.top() / temp;
                oper.pop();
                oper.push(temp);
            } else if (i == "+") {
                temp = oper.top();
                oper.pop();
                temp += oper.top();
                oper.pop();
                oper.push(temp);
            } else if (i == "-") {
                temp = oper.top();
                oper.pop();
                temp = oper.top() - temp;
                oper.pop();
                oper.push(temp);
            } else {
                oper.push(stoi(i));
            }
        }
        return oper.top();
    }
};