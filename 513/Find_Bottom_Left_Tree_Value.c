/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode* root, int* ret, int* depth_max, int depth) {
    if (!root) {
        return;
    }

    if (!root->left && !root->right && depth > *depth_max) {
        *depth_max = depth;
        *ret = root->val;
    }

    dfs(root->left, ret, depth_max, depth + 1);
    dfs(root->right, ret, depth_max, depth + 1);

    return;
}

int findBottomLeftValue(struct TreeNode* root) {
    int ret = root->val; //said root node is not NULL
    int depth_max = 0;
    dfs(root, &ret, &depth_max, 0);
    return ret;
}
