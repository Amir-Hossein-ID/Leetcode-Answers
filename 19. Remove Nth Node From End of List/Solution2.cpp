#include <bits/stdc++.h>

using namespace std;

int faster = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* before = new ListNode();
        before->next = head;
        ListNode* start = head;
        ListNode* nbefore = before;
        int len = 1;
        while (start != nullptr) {
            start = start->next;
            if (len <= n) {
                len++;
            } else {
                nbefore = nbefore->next;
            }
        }
        nbefore->next = nbefore->next->next;
        return before->next;
    }
};
