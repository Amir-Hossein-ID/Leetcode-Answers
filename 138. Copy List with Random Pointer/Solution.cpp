#include <bits/stdc++.h>

using namespace std;

int faster = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    return 0;
}();

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;

        map<Node*, Node*> addresses;
        addresses[nullptr] = nullptr;

        Node* dummy = new Node(0);
        Node* next = dummy;
        Node* headre = head;
        while (head != nullptr) {
            next->next = new Node(head->val);
            next = next->next;
            addresses[head] = next;
            head = head->next;
        }
        next = dummy->next;
        head = headre;
        while (head != nullptr) {
            next->random = addresses[head->random];
            next = next->next;
            head = head->next;
        }
        return dummy->next;
    }
};
