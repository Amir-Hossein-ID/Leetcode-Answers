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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (!root) return root;
        q.push(root);

        TreeNode *temp, *temp2;

        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            temp2 = temp->left;

            temp->left = temp->right;
            temp->right = temp2;
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }

        return root;
    }
};
