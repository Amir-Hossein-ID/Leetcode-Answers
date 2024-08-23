#include <bits/stdc++.h>

using namespace std;

int faster = [](){
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* next = head;
        int carry = 0;
        int val = 0;
        while (l1 || l2 || carry) {
            val = carry;
            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }
            carry = val / 10;
            val %= 10;
            next->next = new ListNode(val);
            next = next->next;
        }

        return head->next;
    }
};
