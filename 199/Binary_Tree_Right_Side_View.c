/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

void dfs(struct TreeNode* root, int* ret, int* returnSize, int depth) {
    if (!root) {
        return;
    }

    if (depth > *returnSize) {
        ret[(*returnSize)++] = root->val;
    }

    dfs(root->right, ret, returnSize, depth + 1);
    dfs(root->left, ret, returnSize, depth + 1);
    return;
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    if (!root) {
        return NULL;
    }

    int* ret = (int*)malloc(1000 * sizeof(int));
    if (!ret) {
        return NULL;
    }

    dfs(root, ret, returnSize, 1);
    return ret;
}
