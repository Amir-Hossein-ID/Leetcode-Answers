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
        ListNode* answer = new ListNode(0);
        ListNode* last = answer;
        while (true) {
            ListNode* curmin = nullptr;
            int minind = -1;
            for (int i = 0; i < lists.size(); i++) {
                if (lists[i] && (minind == -1 || lists[i]->val < curmin->val)) {
                    curmin = lists[i];
                    minind = i;
                }
            }
            if (minind == -1) break;
            last->next = curmin;
            last = curmin;
            lists[minind] = curmin->next;
        }

        return answer->next;
    }
};
