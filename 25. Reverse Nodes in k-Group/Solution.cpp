#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* first = new ListNode(0);
        int count = 1;
        ListNode *lastend = first, *start = head, *last = head, *temp;
        while (last != nullptr) {
            if (last && count == k) {
                temp = last->next;
                last->next = nullptr;
                lastend->next = reverseList(start);
                lastend = start;
                start->next = temp;
                start = temp;
                last = temp;
                count = 1;
            }
            if (last) last = last->next;
            count++;
        }
        return first->next;
    }

    ListNode* reverseList(ListNode* head) { // the solution for 206. Reverse Linked List
        ListNode* before = nullptr;
        ListNode* after;
        while (head != nullptr) {
            after = head->next;
            head->next = before;
            before = head;
            head = after;
        }
        return before;
    }
};
