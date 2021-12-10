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
    int ans;
    int toLeaf(TreeNode *u) {
        if(!u) return -1;
        return (max(toLeaf(u->left), toLeaf(u->right)) + 1);
    };
    int maxLength(TreeNode *u) {
        if(!u->left && !u->right) return 0;
        if(!u->left) return toLeaf(u->right) + 1;
        if(!u->right) return toLeaf(u->left) + 1;
        return toLeaf(u->left) + toLeaf(u->right) + 2;
    };
    void dfs(TreeNode *u) {
        if(!u) return;
        ans = max(ans, maxLength(u));
        dfs(u->right);
        dfs(u->left);
    };
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};