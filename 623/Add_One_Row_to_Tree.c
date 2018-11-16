/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int v, int d, int depth) {
    if (!root) {
        return;
    }

    if (d - 1 == depth) {
        struct TreeNode* left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        left->val = v;
        left->left = root->left;
        left->right = NULL;
        root->left = left;

        struct TreeNode* right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        right->val = v;
        right->right = root->right;
        right->left = NULL;
        root->right = right;

        return;
    }

    dfs(root->left, v, d, depth + 1);
    dfs(root->right, v, d, depth + 1);
    return;
}

struct TreeNode* addOneRow(struct TreeNode* root, int v, int d) {
    // The given d is in range [1, maximum depth of the given tree + 1].
    // The given binary tree has at least one tree node.
    if (d == 1) {
        struct TreeNode* ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        if (!ret) {
            return NULL;
        }
        ret->val = v;
        ret->right = NULL;
        ret->left = root;
        return ret;
    }

    dfs(root, v, d, 1);
    return root;
}
