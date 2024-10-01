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
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        new_func(root);
        return ans;
    }

    int new_func(TreeNode* node) {
        if (!node) return 0;
        int right = new_func(node->right);
        int left = new_func(node->left);
        ans = max(ans, right + left);
        return max(right, left) + 1;
    }
};
