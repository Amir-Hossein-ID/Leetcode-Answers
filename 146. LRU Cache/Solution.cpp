#include <bits/stdc++.h>

using namespace std;

// not my idea :(

struct DListNode {
    int val;
    int key;
    DListNode *next;
    DListNode *prev;
    DListNode(int k, int x) : key(k), val(x), next(nullptr), prev(nullptr) {}
};

class LRUCache {
public:
    int cap;
    DListNode* left;
    DListNode* right;
    unordered_map<int, DListNode*> values;
    LRUCache(int capacity) {
        cap = capacity;
        left = new DListNode(-1, -1);
        right = new DListNode(-1, -1);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if (values.find(key) != values.end()) {
            DListNode* temp = values[key];
            // del node
            DListNode* temp2;
            temp2 = temp->prev;
            temp2->next = temp->next;
            temp2->next->prev = temp2;

            // add node at the end
            right->prev->next = temp;
            temp->next = right;
            temp->prev = right->prev;
            right->prev = temp;

            return temp->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        DListNode* temp;
        if (values.find(key) != values.end()) {
            temp = values[key];
            temp->val = value;
            // del node
            DListNode* temp2;
            temp2 = temp->prev;
            temp2->next = temp->next;
            temp2->next->prev = temp2;
        } else {
            temp = new DListNode(key, value);
            values[key] = temp;
        }
        if (values.size() > cap) {
            values.erase(left->next->key);
            left->next = left->next->next;
            left->next->prev = left;
        }
        // add node at the end
        right->prev->next = temp;
        temp->next = right;
        temp->prev = right->prev;
        right->prev = temp;
    }
};
