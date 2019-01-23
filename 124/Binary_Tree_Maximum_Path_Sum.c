/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX_INT ((unsigned)(-1)>>1)
#define MIN_INT (~MAX_INT)

int max(int a, int b) {
    return a > b ? a : b;
}

int dfs(struct TreeNode* root, int* ret) {
    if (!root) {
        return 0;
    }

    int left = max(0, dfs(root->left, ret));
    int right = max(0, dfs(root->right, ret));

    *ret = max(*ret, left + right + root->val);
    return root->val + max(left, right);
}

int maxPathSum(struct TreeNode* root) {
    if (!root) {
        return 0;
    }
    int ret = MIN_INT;

    dfs(root, &ret);
    return ret;
}
