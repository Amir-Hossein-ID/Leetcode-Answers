#include<bits/stdc++.h>

using namespace std;

int faster = [](){
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *s = head, *f = head;
        if (!f) return false;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
            if (s == f) return true;
        }
        return false;
    }
};
