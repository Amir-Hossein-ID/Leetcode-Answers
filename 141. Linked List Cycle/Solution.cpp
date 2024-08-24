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
    bool hasCycle(ListNode *head) { // bad solution
        unordered_set<ListNode*> history;
        while (head) {
            history.insert(head);
            head = head->next;
            if (history.find(head) != history.end()) {
                return true;
            }
        }
        return false;
    }
};
