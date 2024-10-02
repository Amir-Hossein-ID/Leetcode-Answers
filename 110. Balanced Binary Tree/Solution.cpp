#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return deep(root) != -1 ? true : false;
    }

    int deep(TreeNode* node) {
        if (!node) return 0;
        int right = deep(node->right);
        int left = deep(node->left);
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(right, left) + 1;
    }
};
