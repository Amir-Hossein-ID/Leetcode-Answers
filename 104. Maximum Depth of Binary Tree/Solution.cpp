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
    int maxDepth(TreeNode* root) {
        return go_deep(root);
    }

    int go_deep(TreeNode* tree) {
        if (tree) {
            return 1 + max(go_deep(tree->right), go_deep(tree->left));
        } else {
            return 0;
        }
    }
};
