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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0) {
            return nullptr;
        }

        while (size > 1) {
            for (int i = 0; i < size / 2; i++) {
                lists[i] = mergeTwoLists(lists[i], lists[size - i - 1]);
            }
            size = (size + 1) / 2;
        }

        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) { // copied from question 21
        ListNode* answer = new ListNode(0);
        ListNode* last = answer;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                last->next = list1;
                last = list1;
                list1 = list1->next;
            } else {
                last->next = list2;
                last = list2;
                list2 = list2->next;
            }
        }
        if (list1) last->next = list1;
        else if (list2) last->next = list2;
        return answer->next;
    }
};
