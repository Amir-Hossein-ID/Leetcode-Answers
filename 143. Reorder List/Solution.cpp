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
    void reorderList(ListNode* head) {
        ListNode *start = head, *middle = head, *end = head;
        while (end->next != nullptr) {
            middle = middle->next;
            end = end->next;
            if (end->next != nullptr) end = end->next;
        }

        ListNode* reverse = nullptr;
        ListNode* after, *temp;
        while (middle != nullptr) {
            after = middle->next;
            middle->next = reverse;
            reverse = middle;
            middle = after;
        }
        after = head;
        while (reverse->next != nullptr) {
            temp = after->next;
            after->next = reverse;
            reverse = reverse->next;
            after = after->next;
            if (temp != reverse) {
                after->next = temp;
                after = after->next;
            } else {
                break;
            }
        }
    }
};
