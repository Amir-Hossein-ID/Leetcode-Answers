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
        ListNode* start = head;
        int len = 0;
        while (start != nullptr) {
            start = start->next;
            len += 1;
        }
        int where = 0;
        ListNode* before = new ListNode();
        before->next = head;
        start = before;
        while (where != len - n) {
            where += 1;
            start = start->next;
        }
        start->next = start->next->next;
        return before->next;
    }
};
